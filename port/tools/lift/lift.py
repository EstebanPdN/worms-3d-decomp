#!/usr/bin/env python3
"""Convierte fuentes C/C++ recuperadas (ILP32) en C++ de núcleo con punteros de 32 bits.

Usa el AST JSON de clang con objetivo powerpc-none-eabi, de modo que los tipos y
conversiones son los del original. Solo escribe en port/; nunca toca la fuente.

Reglas (ver docs/port-architecture.md):
- Todo puntero declarado (campo, global, local, parámetro, retorno, typedef) pasa a P<T>.
- Conversión entero->puntero: se envuelve el operando en w3d::G(...).
- Conversión puntero->entero: se envuelve el operando en w3d::H(...).
- Cast a un puntero con punteros anidados o a puntero a función: se reescribe el tipo.
- sizeof(T*) y long: 4 B como en el original (long se reescribe a int).
- Parámetro T* de una plantilla de función: puntero real, para que T se deduzca como en el original;
  los argumentos de esa posición se envuelven en w3d::R(...).
- Disposición de GCC 2.95 (comprobada con su cc1plus, ver port/tools/lift/layout_gate.py):
  vptr de 4 B tras los campos de la primera clase polimórfica, base vacía de 1 B y sin usar el relleno final de una base.
- virtual se baja a tabla explícita: la clase deja de ser polimórfica para clang (ver lower_member).
"""
import json, os, re, subprocess, sys, collections
from dataclasses import dataclass, field

CLANG = 'clang'
# size_t debe ser unsigned int como en GCC 2.95: con powerpc-none-eabi es unsigned long y todo operator new
# propio da error, lo que dejaba expresiones fuera del AST sin avisar. Las macros de Linux no aplican al original.
AST_TARGET = ['-target', 'powerpc-unknown-linux-gnu', '-U__linux__', '-U__linux', '-Ulinux', '-U__gnu_linux__', '-U__unix__', '-U__unix', '-Uunix']
AST_CXX = ['-x', 'c++', '-std=gnu++98', '-fno-exceptions', '-fno-rtti', '-fno-access-control', '-Wno-error=address-of-temporary']
AST_C = ['-x', 'c', '-std=gnu89', '-Wno-error=implicit-function-declaration', '-Wno-error=implicit-int', '-Wno-error=int-conversion',
         '-Wno-error=incompatible-pointer-types', '-Wno-error=incompatible-function-pointer-types']

# ---------------------------------------------------------------- tipos
TOK = re.compile(r'\s*([A-Za-z_][\w:]*|\d+|\.\.\.|::\*|[*&()\[\]<>,]|[^\s])')

class T: pass
@dataclass
class Base(T):
    text: str
@dataclass
class Ptr(T):
    to: T
    quals: str = ''
@dataclass
class Ref(T):
    to: T
    rv: bool = False
@dataclass
class Arr(T):
    of: T
    n: str
@dataclass
class Fn(T):
    ret: T
    params: list
    variadic: bool
    tail: str = ''
@dataclass
class Mem(T):
    """Puntero a miembro: se queda como puntero del anfitrión, con su firma ya convertida."""
    cls: str
    to: T
    quals: str = ''

def tokenize(s):
    out = []; i = 0
    while i < len(s):
        m = TOK.match(s, i)
        if not m: break
        out.append(m.group(1)); i = m.end()
    return out

class TP:
    def __init__(self, toks): self.t = toks; self.i = 0
    def peek(self): return self.t[self.i] if self.i < len(self.t) else None
    def next(self): self.i += 1; return self.t[self.i-1]
    def base(self):
        """Especificadores hasta el primer token de declarador a profundidad 0."""
        parts = []; depth = 0
        while True:
            k = self.peek()
            if k is None: break
            if k == '<': depth += 1
            elif k == '>' and depth: depth -= 1
            elif depth == 0:
                if k in ('*', '&', '[', ',', ')'): break
                if k.endswith('::') and self.i + 1 < len(self.t) and self.t[self.i + 1] == '*': break
                if k == '(':
                    # typeof(...) o decltype(...) son base; el resto es declarador.
                    if parts and parts[-1] in ('__typeof__', 'typeof', 'decltype', '__attribute__'):
                        d = 0
                        while True:
                            x = self.next(); parts.append(x)
                            if x == '(': d += 1
                            elif x == ')':
                                d -= 1
                                if d == 0: break
                        continue
                    break
            parts.append(self.next())
        return ' '.join(parts)
    def typ(self):
        b = Base(self.base())
        return self.declarator(b)
    def quals(self):
        q = []
        while self.peek() in ('const', 'volatile', 'restrict', '__restrict'):
            q.append(self.next())
        return ' '.join(q)
    def declarator(self, inner):
        """Devuelve el tipo aplicado sobre `inner`, respetando precedencia."""
        k = self.peek()
        if k == '*':
            self.next(); q = self.quals()
            return self.declarator(Ptr(inner, q))
        if k and k.endswith('::') and self.i + 1 < len(self.t) and self.t[self.i + 1] == '*':
            self.next(); self.next(); q = self.quals()
            return self.declarator(Mem(k[:-2], inner, q))
        if k == '&':
            self.next()
            if self.peek() == '&':
                self.next(); return self.declarator(Ref(inner, True))
            return self.declarator(Ref(inner))
        if k == '(':
            # ¿declarador entre paréntesis o lista de parámetros?
            nx = self.t[self.i+1] if self.i+1 < len(self.t) else None
            if nx in ('*', '&', '(', '[') or (nx and nx.endswith('::')):
                self.next()
                sub_start = self.i
                d = 1
                while d:
                    x = self.next()
                    if x == '(': d += 1
                    elif x == ')': d -= 1
                sub_end = self.i - 1
                # primero sufijos sobre inner, luego el subdeclarador
                inner2 = self.suffix(inner)
                save = (self.t, self.i)
                self.t, self.i = self.t[sub_start:sub_end], 0
                r = self.declarator(inner2)
                self.t, self.i = save
                return r
        return self.suffix(inner)
    def suffix(self, inner):
        k = self.peek()
        if k == '[':
            self.next(); n = []
            while self.peek() != ']': n.append(self.next())
            self.next()
            sub = self.suffix(inner)
            return Arr(sub, ' '.join(n))
        if k == '(':
            self.next(); params = []; variadic = False
            while self.peek() != ')':
                if self.peek() == '...': self.next(); variadic = True; continue
                params.append(self.typ())
                if self.peek() == ',': self.next()
            self.next()
            tail = self.quals()
            return Fn(inner, params, variadic, tail)
        return inner

def parse_type(s):
    s = s.replace('__restrict', '').replace('restrict', '')
    p = TP(tokenize(s))
    return p.typ()

def has_ptr(t):
    if isinstance(t, Ptr): return True
    if isinstance(t, Ref): return has_ptr(t.to)
    if isinstance(t, Arr): return has_ptr(t.of)
    if isinstance(t, Fn): return has_ptr(t.ret) or any(has_ptr(p) for p in t.params)
    if isinstance(t, Mem): return has_ptr(t.to)
    if isinstance(t, Base):
        # vector<void *>: el argumento de plantilla es memoria guardada y debe ocupar 4 B.
        if '*' in t.text: return True
        return bool(re.search(r'\blong\b(?!\s+long)', t.text.replace('long long', '')))
    return False

def lift_template_args(t):
    """Foo<Bar *, int> -> Foo<Ptr32<Bar>, int>. El texto puede venir separado en fichas."""
    i = t.find('<')
    if i < 0 or '*' not in t[i:]: return t
    out = []; pos = 0
    while True:
        i = t.find('<', pos)
        if i < 0: out.append(t[pos:]); break
        d = 0; j = i; cuts = [i]
        while j < len(t):
            c = t[j]
            if c in '<(': d += 1
            elif c in '>)':
                d -= 1
                if d == 0: break
            elif c == ',' and d == 1: cuts.append(j)
            j += 1
        if j >= len(t): out.append(t[pos:]); break
        cuts.append(j)
        args = []
        for a_, b_ in zip(cuts, cuts[1:]):
            arg = t[a_ + 1:b_].strip()
            if '*' in arg and not re.fullmatch(r'[\d\s*+()-]+', arg):
                try: arg = rt(parse_type(arg))
                except Exception: pass
            elif '<' in arg:
                arg = lift_template_args(arg)
            args.append(arg)
        out.append(t[pos:i] + '<' + ', '.join(args) + ' >')
        pos = j + 1
    return ''.join(out)

def base_text(b):
    t = lift_template_args(b.text)
    # long -> int: tamaño original de 4 B.
    if 'long' in t:
        t = re.sub(r'\blong\s+long\b', '@@LL@@', t)
        t = re.sub(r'\blong\s+int\b|\bint\s+long\b', 'int', t)
        t = re.sub(r'\blong\b', 'int', t)
        t = t.replace('@@LL@@', 'long long')
    return t

def rt(t, name=''):
    """Declaración C++ de `name` con tipo t y punteros como P<>."""
    n = (' ' + name) if name else ''
    if isinstance(t, Base): return base_text(t) + n
    if isinstance(t, Ptr):
        q = (' ' + t.quals) if t.quals else ''
        return f'Ptr32<{rt(t.to)}>{q}{n}'
    if isinstance(t, Mem):
        q = (' ' + t.quals + ' ') if t.quals else ''
        if isinstance(t.to, (Fn, Arr)): return rt(t.to, f'({t.cls}::*{q}{name})')
        return rt(t.to, f'{t.cls}::*{q}{name}')
    if isinstance(t, Ref):
        a = '&&' if t.rv else '&'
        if isinstance(t.to, (Arr, Fn)): return rt(t.to, f'({a}{name})')
        return f'{rt(t.to)} {a}{name}'
    if isinstance(t, Arr): return rt(t.of, f'{name}[{t.n}]')
    if isinstance(t, Fn):
        ps = [rt(p) for p in t.params]
        if t.variadic: ps.append('...')
        if not ps: ps = ['void']
        tail = (' ' + t.tail) if t.tail else ''
        return rt(t.ret, f'{name}({", ".join(ps)}){tail}')
    raise ValueError(t)

def render(s, name=''):
    return rt(parse_type(s), name)

# ---------------------------------------------------------------- AST
@dataclass
class Edit:
    start: int
    end: int
    text: str

class Pos:
    """Decodifica posiciones del JSON (file/line se omiten si no cambian)."""
    __slots__ = ('file',)
    def __init__(self): self.file = None

@dataclass
class FileEdits:
    edits: dict = field(default_factory=dict)  # (start,end)->text

# ---------------------------------------------------------------- virtual
# Regla medida con el cc1plus de ProDG 3.7 -fvtable-thunks (GCC 2.95):
# - La primera clase polimórfica sin base polimórfica añade el vptr (4 B) DESPUÉS de sus campos.
# - Sus derivadas lo comparten con la primera base polimórfica, esté donde esté (M1 : NoV, V1).
# - Tabla: 2 entradas de cabecera, luego las virtuales nuevas en orden de declaración (el destructor cuenta).
# - Una sobrescritura ocupa la ranura de la base que la introdujo y se llama con this ajustado a esa base.
# - Destructores: segundo argumento entero; bit 1 = delete. p->~T() pasa 2 y delete p pasa 3.
@dataclass
class VM:
    node: dict
    rec: object
    key: tuple
    kind: str                # 'm' método, 'd' destructor
    slot: int = None         # ranura propia, si la introduce esta clase
    over: object = None      # base de la que hereda la ranura
    over_text: str = ''
    bodied: bool = False     # definida en el cuerpo de la clase
    defined: bool = False    # definida en esta unidad

class Rec:
    def __init__(self, n, scope, tmpl):
        self.node = n; self.id = n.get('id'); self.name = n.get('name') or ''; self.scope = scope; self.tmpl = tmpl
        self.bases = []; self.base_texts = []; self.vms = []; self.poly = False; self.primary = None; self.primary_text = ''
        self.vfield = None; self.own_vptr = False; self.table = []; self.keys = set(); self.user_ctor = False
        self.dtor = None; self.first_field = None; self.implicit_default_used = False; self.has_tail = False

def rname(name):
    return 'w3d_r_' + name

class Lifter:
    def __init__(self, main, lang, flags, roots, keep_defs=None, ledger_names=None):
        self.main = os.path.realpath(main); self.lang = lang; self.flags = flags; self.roots = [os.path.realpath(r) for r in roots]
        self.fe = collections.defaultdict(FileEdits); self.cur_file = None; self.stats = collections.Counter(); self.problems = []
        self.keep_defs = keep_defs
        self.groups = {}
        self.body = {}
        self.ctor_done = set()
        self.c_linkage = 0
        self.pmf_fields = []
        self.tail = []            # Texto al final de la unidad principal.
        self.ledger_names = ledger_names or set()
        self.skip_ids = set(); self.recs = {}; self.by_name = {}; self.typedefs = {}; self.ftmpl_ids = {}; self.tmpl_ptr_pos = {}; self.vmethods = {}; self.member_rec = {}
        self.template_names = set()
        self.wrapped = set()
        self.define_ranges = {}
    def run(self):
        lang_fl = AST_C if self.lang == 'c' else AST_CXX
        cmd = [CLANG] + AST_TARGET + ['-fsyntax-only', '-w', '-Xclang', '-ast-dump=json',
               '-ferror-limit=0', '-funsigned-char', '-D__W3D_PORT__=1'] + self.flags + lang_fl
        cmd.append(self.main)
        p = subprocess.run(cmd, capture_output=True, errors='replace')
        if not p.stdout: raise RuntimeError('clang sin salida: ' + p.stderr[:500])
        self.ast_err = p.stderr
        self.included = set()
        d = subprocess.run([CLANG] + AST_TARGET + ['-fsyntax-only', '-w', '-H', '-funsigned-char', '-D__W3D_PORT__=1'] + self.flags + lang_fl + [self.main], capture_output=True, errors='replace')
        for line in d.stderr.splitlines():
            m = re.match(r'^\.+ (.*)$', line)
            if m:
                q = os.path.realpath(m.group(1).strip())
                if any(q.startswith(r + os.sep) for r in self.roots): self.included.add(q)
        ast = json.loads(p.stdout)
        self.noproto = {}; self.noproto_args = {}
        # Un error en el AST deja código sin convertir sin avisar: se cuenta siempre.
        ast_errors = [l for l in p.stderr.splitlines() if ': error:' in l or ': fatal error:' in l]
        if ast_errors:
            self.stats['ast_error_units'] += 1
            self.problems.append('AST con errores: ' + ast_errors[0].split('WORMS 3D/')[-1][:160])
        self.prepass(ast)
        self.walk_top(ast)
        for did, (f, a, b_) in self.noproto.items():
            args = self.noproto_args.get(did)
            if args:
                self.edit(f, a, b_, '(' + ', '.join(args) + ')')
                self.stats['noproto_fixed'] += 1
        return self
    # pasada previa: clases, tablas y plantillas de función
    @staticmethod
    def mentions_tparam(t, names):
        if isinstance(t, Base): return any(re.search(r'\b' + re.escape(x) + r'\b', t.text) for x in names)
        if isinstance(t, (Ptr, Ref)): return Lifter.mentions_tparam(t.to, names)
        if isinstance(t, Arr): return Lifter.mentions_tparam(t.of, names)
        return False
    def prepass(self, ast):
        self.pre(ast, [], False)
    def pre(self, n, scope, tmpl):
        k = n.get('kind')
        if k in ('TypedefDecl', 'TypeAliasDecl'):
            ty = n.get('type', {}).get('qualType')
            if n.get('name') and ty: self.typedefs[n['name']] = ty
            return
        if k == 'NamespaceDecl':
            for c in n.get('inner', []): self.pre(c, scope + [n.get('name', '')], tmpl)
            return
        if k in ('FunctionTemplateDecl', 'ClassTemplateDecl') and n.get('name') and re.fullmatch(r'[A-Za-z_]\w*', n['name']):
            self.template_names.add(n['name'])
        if k == 'FunctionTemplateDecl':
            names = {c.get('name') for c in n.get('inner', []) if c.get('kind') == 'TemplateTypeParmDecl' and c.get('name')}
            for c in n.get('inner', []):
                if c.get('kind') in ('FunctionDecl', 'CXXMethodDecl', 'CXXConstructorDecl', 'CXXConversionDecl', 'CXXDestructorDecl'):
                    self.ftmpl_ids[c.get('id')] = names
                    parms = [x for x in c.get('inner', []) if x.get('kind') == 'ParmVarDecl']
                    pos = set()
                    for i, x in enumerate(parms):
                        try: t = parse_type(x.get('type', {}).get('qualType', ''))
                        except Exception: continue
                        if isinstance(t, Ptr) and not isinstance(t.to, Fn) and self.mentions_tparam(t.to, names): pos.add(i)
                    if pos:
                        lo = sum(1 for x in parms if not x.get('init'))
                        self.tmpl_ptr_pos.setdefault(c.get('name'), []).append((lo, len(parms), pos))
                    for x in c.get('inner', []): self.pre(x, scope, True)
                    break
            return
        if k == 'ClassTemplateDecl':
            for c in n.get('inner', []):
                if c.get('kind') == 'CXXRecordDecl': self.pre(c, scope, True)
            return
        if k in ('ClassTemplateSpecializationDecl', 'ClassTemplatePartialSpecializationDecl') and not n.get('isExplicit', True): return
        if k in ('CXXRecordDecl', 'ClassTemplateSpecializationDecl', 'ClassTemplatePartialSpecializationDecl') and n.get('completeDefinition'):
            self.pre_record(n, scope, tmpl or k != 'CXXRecordDecl')
            return
        if k in ('CXXMethodDecl', 'CXXConstructorDecl', 'CXXDestructorDecl'):
            # Definición fuera de la clase.
            prev = n.get('previousDecl')
            if prev in self.member_rec:
                self.member_rec[n.get('id')] = self.member_rec[prev]
                if prev in self.vmethods:
                    self.vmethods[n.get('id')] = self.vmethods[prev]
                    if any(c.get('kind') == 'CompoundStmt' for c in n.get('inner', [])): self.vmethods[prev].defined = True
        if n.get('isImplicit'): return
        for c in n.get('inner', []): self.pre(c, scope, tmpl)
    def canon_type(self, t):
        text = rt(t)
        for _ in range(5):
            new = re.sub(r'\b[A-Za-z_]\w*\b', lambda m: self.typedef_text(m.group(0)), text)
            if new == text: break
            text = new
        text = re.sub(r'\b(struct|class|union|enum|typename)\s+', '', text)
        text = re.sub(r'\s+', ' ', text).strip()
        return re.sub(r'^const ', '', text) if not isinstance(t, (Ptr, Ref)) else text
    def typedef_text(self, w):
        ty = self.typedefs.get(w)
        if ty is None or re.search(r'\b' + re.escape(w) + r'\b', ty): return w
        try: return rt(parse_type(ty))
        except Exception: return w
    def sig_key(self, name, ty):
        try: t = parse_type(ty)
        except Exception: return (name, ty, False)
        if not isinstance(t, Fn): return (name, ty, False)
        return (name, tuple(self.canon_type(p) for p in t.params), 'const' in t.tail)
    def find_rec(self, text):
        t = re.sub(r'\b(struct|class|const|volatile|typename)\b', ' ', text).strip()
        for _ in range(5):
            short = re.sub(r'<.*>', '', t).strip().split('::')[-1].strip()
            if short in self.by_name: return self.by_name[short]
            if short in self.typedefs: t = re.sub(r'\b(struct|class|const|volatile|typename)\b', ' ', self.typedefs[short]).strip()
            else: return None
        return None
    def pre_record(self, n, scope, tmpl):
        r = Rec(n, scope, tmpl); dd = n.get('definitionData', {})
        r.poly = bool(dd.get('isPolymorphic'))
        for b in n.get('bases', []):
            ty = b.get('type', {}).get('qualType', '')
            r.bases.append(self.find_rec(ty)); r.base_texts.append(ty)
        if r.name: self.by_name[r.name] = r
        self.recs[r.id] = r
        methods = []
        for c in n.get('inner', []):
            ck = c.get('kind')
            if ck in ('CXXMethodDecl', 'CXXDestructorDecl', 'CXXConstructorDecl'):
                if ck == 'CXXConstructorDecl' and c.get('isImplicit'):
                    if c.get('isUsed') and c.get('type', {}).get('qualType', '').startswith('void ()'): r.implicit_default_used = True
                    continue
                if c.get('isImplicit'): continue
                self.member_rec[c.get('id')] = r
                if ck == 'CXXConstructorDecl': r.user_ctor = True
                else: methods.append(c)
                if ck == 'CXXDestructorDecl': r.dtor = c
            elif ck == 'FieldDecl' and r.first_field is None and not c.get('isImplicit'):
                r.first_field = c
            elif ck in ('CXXRecordDecl', 'ClassTemplateDecl', 'FunctionTemplateDecl', 'TypedefDecl', 'TypeAliasDecl', 'ClassTemplateSpecializationDecl'):
                self.pre(c, scope + [r.name], tmpl)
        if r.poly:
            for b, tx in zip(r.bases, r.base_texts):
                if b is not None and b.poly: r.primary = b; r.primary_text = tx; break
            if r.primary is not None: r.vfield = r.primary.vfield
            else: r.own_vptr = True; r.vfield = 'w3d_vptr_' + re.sub(r'\W', '_', r.name or 'anon')
            table = list(r.primary.table) if r.primary is not None else []
            inherited = set()
            for b in r.bases:
                if b is not None: inherited |= b.keys
            r.keys = set(inherited)
            for c in methods:
                kind = 'd' if c.get('kind') == 'CXXDestructorDecl' else 'm'
                key = ('~',) if kind == 'd' else self.sig_key(c.get('name'), c.get('type', {}).get('qualType', ''))
                is_virtual = bool(c.get('virtual')) or key in inherited
                if not is_virtual: continue
                vm = VM(c, r, key, kind, bodied=any(i.get('kind') == 'CompoundStmt' for i in c.get('inner', [])))
                vm.defined = vm.bodied
                if key in inherited:
                    for b, tx in zip(r.bases, r.base_texts):
                        if b is not None and key in b.keys: vm.over = b; vm.over_text = tx; break
                else:
                    vm.slot = 2 + len(table); table.append(key)
                r.keys.add(key); r.vms.append(vm); self.vmethods[c.get('id')] = vm
            r.table = table
        # Cuerpos de métodos en línea: pueden declarar clases locales.
        for c in n.get('inner', []):
            if c.get('kind') in ('CXXMethodDecl', 'CXXConstructorDecl', 'CXXDestructorDecl') and not c.get('isImplicit'):
                for x in c.get('inner', []):
                    if x.get('kind') == 'CompoundStmt': self.pre(x, scope + [r.name], tmpl)
    # bajada de virtual
    @staticmethod
    def gcc2_name(r):
        """Nombre de clase en el esquema GCC 2.95: 7CostBase o Q21A1B. None en plantillas."""
        if r.tmpl or not r.name: return None
        parts = [x for x in r.scope if x] + [r.name]
        if any('<' in x for x in parts): return None
        if len(parts) == 1: return f'{len(r.name)}{r.name}'
        return f'Q{len(parts)}' + ''.join(f'{len(x)}{x}' for x in parts)
    def qualified(self, r):
        return '::'.join([x for x in r.scope if x] + [r.name])
    def vt_assign(self, r):
        """Asignaciones de vptr de un constructor o destructor de r."""
        c = self.gcc2_name(r)
        if c is None:
            self.stats['vt_sin_nombre'] += 1
            return ''
        out = []
        field = f'this->{r.primary_text}::{r.vfield}' if r.primary is not None else f'this->{r.vfield}'
        out.append(self.set_vptr(field, '__vt_' + c))
        # Bases polimórficas secundarias: si r sobrescribe algo suyo tiene tabla propia __vt_<r>.<base>.
        for b, tx in zip(r.bases, r.base_texts):
            if b is None or not b.poly or b is r.primary: continue
            own = {vm.key for vm in r.vms if vm.over is b}
            if own and self.gcc2_name(b):
                out.append(self.set_vptr(f'this->{tx}::{b.vfield}', f'__vt_{c}.{self.gcc2_name(b)}'))
        return ' '.join(out)
    @staticmethod
    def set_vptr(field, sym):
        var = 'w3d_vt_' + re.sub(r'\W', '_', sym)
        return f'W3D_SET_VPTR({field}, {var}, "{sym}");'
    def lower_member(self, n, k, off, ln, mac, b, e, f, m):
        r = self.member_rec.get(n.get('id'))
        if r is None or not r.poly: return
        s = self.src(f)
        body = next((c for c in n.get('inner', []) if c.get('kind') == 'CompoundStmt'), None)
        if k in ('CXXConstructorDecl', 'CXXDestructorDecl') and body is not None:
            o = body.get('range', {}).get('begin', {}).get('offset')
            if o is None or mac or m: self.stats['vptr_ctor_in_macro'] += 1
            else:
                t_ = self.vt_assign(r)
                if t_: self.edit(f, o + 1, o + 1, ' ' + t_ + ' '); self.stats['vptr_set'] += 1
        vm = self.vmethods.get(n.get('id'))
        if vm is None: return
        if mac or m:
            self.problems.append(f'virtual dentro de macro: {r.name}::{n.get("name")}'); return
        in_class = n.get('previousDecl') is None or n.get('previousDecl') not in self.vmethods
        # El tipo de retorno convertido ya omite virtual; si no se reescribe hay que quitarlo aquí.
        keep_spec = False
        if k == 'CXXMethodDecl':
            try: keep_spec = has_ptr(parse_type(n.get('type', {}).get('qualType', '')).ret)
            except Exception: pass
        if not keep_spec:
            mv = re.search(r'\bvirtual\b\s*', s[b:off])
            if mv: self.edit(f, b + mv.start(), b + mv.end(), '')
        end = e
        tail = s[off + ln:e] if e is not None else ''
        pure = re.search(r'=\s*0\s*$', tail)
        label = ''
        if k == 'CXXMethodDecl':
            if not re.fullmatch(r'[A-Za-z_]\w*', n.get('name', '')):
                self.problems.append(f'virtual con nombre de operador: {r.name}::{n.get("name")}'); return
            self.edit(f, off, off + ln, rname(n['name']))
            if in_class and body is None and n.get('mangledName') and not r.tmpl:
                label = f' __asm__(W3D_SYM("{n["mangledName"]}"))'
        if pure:
            self.edit(f, off + ln + pure.start(), e, label)
        elif label:
            self.edit(f, e, e, label)
        self.stats['virtual_lowered'] += 1
    def dispatcher(self, r, vm):
        """Método con el nombre original que llama por la tabla: los sitios de llamada no cambian."""
        c = vm.node; name = c.get('name')
        t = parse_type(c.get('type', {}).get('qualType', ''))
        ret = t.ret
        decl_ps = []; call_ps = []; fwd = []; fn_ps = ['w3d_u32']
        parms = [x for x in c.get('inner', []) if x.get('kind') == 'ParmVarDecl']
        for i, p in enumerate(t.params):
            nm = f'w3d_a{i}'
            dflt = ''
            if i < len(parms) and parms[i].get('init'): dflt = ' = 0' if parms[i].get('init') else ''
            decl_ps.append(rt(p, nm) + dflt); fwd.append(nm)
            if isinstance(p, Ref):
                # En la tabla todo viaja en la forma de 32 bits, también las referencias.
                fn_ps.append('w3d_u32'); call_ps.append(f'w3d::h2g(__builtin_addressof({nm}))')
            else:
                fn_ps.append(rt(p)); call_ps.append(nm)
        if t.variadic:
            self.problems.append(f'virtual variádica: {r.name}::{name}'); return ''
        cv = ' const' if 'const' in t.tail else ''
        head = f'__attribute__((always_inline)) inline {rt(ret, name + "(" + ", ".join(decl_ps) + ")")}{cv}'
        if vm.over is not None:
            inner = f'this->{vm.over_text}::{name}({", ".join(fwd)})'
            base_vm = next((v for v in vm.over.vms if v.key == vm.key), None)
            same = base_vm is None or rt(parse_type(base_vm.node.get('type', {}).get('qualType', '')).ret) == rt(ret)
            if isinstance(ret, Base) and ret.text == 'void': return f'{head} {{ {inner}; }}'
            return f'{head} {{ return {inner if same else "(" + rt(ret) + ")" + inner}; }}'
        args = ', '.join(['w3d::h2g(this)'] + call_ps); ps = ', '.join(fn_ps)
        slot = f'w3d::vfn(this->{r.vfield}, {vm.slot})'
        if isinstance(ret, Ref):
            return f'{head} {{ return *({rt(ret.to)} *)w3d::g2h(((w3d_u32 (*)({ps})){slot})({args})); }}'
        call = f'(({rt(ret, "(*)(" + ps + ")")}){slot})({args})'
        if isinstance(ret, Base) and ret.text == 'void': return f'{head} {{ {call}; }}'
        return f'{head} {{ return {call}; }}'
    def class_tail(self, r):
        """Texto al final del cuerpo de la clase. Se devuelve sin tocar los ficheros."""
        out = []
        n = r.node
        if self.lang != 'c' and n.get('definitionData', {}).get('isEmpty') and not n.get('bases') and n.get('tagUsed') != 'union' and r.name:
            # GCC 2.95 no comprime bases vacías: ocupan 1 B y lo que sigue se alinea detrás.
            out.append('char w3d_empty;')
        if not r.poly: return out
        for vm in r.vms:
            if vm.kind == 'm':
                d = self.dispatcher(r, vm)
                if d: out.append(d)
            elif vm.slot is not None:
                out.append(f'__attribute__((always_inline)) inline void w3d_vdt(int w3d_in) const {{ ((void (*)(w3d_u32, int))w3d::vfn(this->{r.vfield}, {vm.slot}))(w3d::h2g(this), w3d_in); }}')
        with_dt = [(b, tx) for b, tx in zip(r.bases, r.base_texts) if b is not None and ('~',) in b.keys]
        if len(with_dt) > 1 and not any(vm.kind == 'd' and vm.slot is not None for vm in r.vms):
            out.append(f'__attribute__((always_inline)) inline void w3d_vdt(int w3d_in) const {{ this->{with_dt[0][1]}::w3d_vdt(w3d_in); }}')
        if r.own_vptr:
            out.append(f'Ptr32<void> {r.vfield}{self.base_align_attr(r) if r.first_field is None else ""};')
        if not r.user_ctor and r.implicit_default_used and r.name:
            t_ = self.vt_assign(r)
            if t_: out.append(f'{r.name}() {{ {t_} }}'); self.stats['vptr_ctor_added'] += 1
        # Destructor virtual: la dirección original recibe (this, int).
        c = self.gcc2_name(r)
        if ('~',) in r.keys and c:
            dt = '_._' + c
            if dt in self.ledger_names:
                out.append(f'void w3d_dt_ic(int w3d_in) __asm__(W3D_SYM("{dt}"));')
                self.tail.append(f'void {self.qualified(r)}::w3d_dt_ic(int w3d_in) {{ this->~{r.name}(); if (w3d_in & 1) operator delete(this); }}')
                self.stats['dtor_in_charge'] += 1
            vm = next((v for v in r.vms if v.kind == 'd'), None)
            if vm is not None and not vm.defined and vm.node.get('isUsed') and vm.node.get('mangledName'):
                # Solo declarado aquí: la llamada directa de C++ no lleva el segundo argumento.
                d1 = vm.node['mangledName']; d2 = d1.replace('D1Ev', 'D2Ev')
                self.tail.append(f'W3D_DT_THUNK("{d1}", 2, "{dt}");')
                self.tail.append(f'W3D_DT_THUNK("{d2}", 0, "{dt}");')
                self.stats['dtor_thunk'] += 1
        # Métodos definidos en el cuerpo de la clase: el símbolo original lo da un trampolín si la unidad es su dueña.
        for vm in r.vms:
            if vm.kind != 'm' or not vm.bodied or not vm.node.get('mangledName') or r.tmpl: continue
            if not self.owns_member(r, vm.node.get('name')): continue
            nm = vm.node['name']; t = parse_type(vm.node.get('type', {}).get('qualType', ''))
            ps = [rt(p, f'w3d_a{i}') for i, p in enumerate(t.params)]; fwd = ', '.join(f'w3d_a{i}' for i in range(len(ps)))
            cv = ' const' if 'const' in t.tail else ''
            out.append(f'{rt(t.ret, "w3d_x_" + nm + "(" + ", ".join(ps) + ")")}{cv} __asm__(W3D_SYM("{vm.node["mangledName"]}"));')
            self.tail.append(f'{rt(t.ret, self.qualified(r) + "::w3d_x_" + nm + "(" + ", ".join(ps) + ")")}{cv} {{ return this->{rname(nm)}({fwd}); }}')
            self.stats['virtual_trampoline'] += 1
        return out
    def owns_member(self, r, name):
        c = self.gcc2_name(r)
        if not c: return False
        return any(x.startswith(f'{name}__{c}') or x.startswith(f'{name}__C{c}') for x in self.ledger_names)
    @staticmethod
    def base_align_attr(r):
        # GCC 2.95 no reutiliza el relleno final de una base: el primer campo va tras su tamaño completo.
        if not r.base_texts: return ''
        return ' __attribute__((' + ', '.join(f'aligned(__alignof__({t}))' for t in r.base_texts) + '))'
    def lower_delete(self, n, b, e, f, m):
        if n.get('isArray') or n.get('isGlobal') or not n.get('inner'): return
        op = n['inner'][0]
        ty = op.get('type', {}).get('qualType', '')
        try: t = parse_type(ty)
        except Exception: return
        if not isinstance(t, Ptr) or not isinstance(t.to, Base): return
        r = self.find_rec(t.to.text)
        builtin = re.fullmatch(r'(const |volatile |unsigned |signed |struct |class )*(void|char|short|int|long|float|double|bool)( const)?', t.to.text)
        if builtin: return
        if r is None or ('~',) in r.keys:
            sb, se, sf, _, sm = self.rng(op)
            if sb is None or se is None or m or sm or not self.in_scope(sf):
                self.stats['delete_in_macro'] += 1; return
            self.edit(sf, b, sb, 'w3d::vdelete('); self.edit(sf, se, se, ')')
            self.stats['virtual_delete'] += 1
    def lower_member_expr(self, n, parent):
        vm = self.vmethods.get(n.get('referencedMemberDecl'))
        if vm is None: return
        rg = n.get('range', {}); end = rg.get('end', {})
        if 'expansionLoc' in end or 'expansionLoc' in rg.get('begin', {}): self.stats['member_call_in_macro'] += 1; return
        self.loc(rg.get('begin')); f = self.cur_file
        self.loc(end); f = self.cur_file
        if not self.in_scope(f): return
        s = self.src(f)
        tok = end.get('offset'); tl = end.get('tokLen', 0)
        if tok is None: return
        before = s[:tok].rstrip()
        if vm.kind == 'd':
            # p->~T(): por la tabla con 2, como GCC. p->T::~T() queda directo.
            ti = s.rfind('~', 0, tok + 1)
            if ti < 0 or s[:ti].rstrip().endswith('::') or parent is None or parent.get('kind') != 'CXXMemberCallExpr': return
            cb, ce, cf, _, cm = self.rng(parent)
            if ce is None or cm: return
            self.edit(f, ti, ce, 'w3d_vdt(2)')
            self.stats['virtual_dtor_call'] += 1
            return
        qualified = before.endswith('::')
        direct = False
        if not n.get('isArrow') and n.get('inner'):
            o = n['inner'][0]
            while o.get('kind') in ('ImplicitCastExpr', 'ParenExpr') and o.get('inner'): o = o['inner'][0]
            if o.get('kind') == 'DeclRefExpr':
                direct = '&' not in o.get('referencedDecl', {}).get('type', {}).get('qualType', '')
            elif o.get('kind') == 'MemberExpr':
                direct = o.get('type', {}).get('qualType', '') != '' and '&' not in o.get('type', {}).get('qualType', '') and not o.get('isArrow', False)
        if qualified or direct:
            # Llamada estática: va al cuerpo real, como en el original.
            self.edit(f, tok, tok + tl, rname(vm.node['name']))
            self.stats['virtual_direct_call'] += 1
    # posiciones
    def loc(self, l):
        # clang solo escribe "file" cuando cambia respecto a la última ubicación impresa,
        # así que hay que seguir ese estado aparte del fichero de la ubicación que se devuelve.
        if not l: return None, None, False
        if 'spellingLoc' in l or 'expansionLoc' in l:
            s = l.get('spellingLoc', {}); e = l.get('expansionLoc', {})
            if 'file' in s: self.last_file = s['file']
            sf = getattr(self, 'last_file', None)
            if 'file' in e: self.last_file = e['file']
            ef = getattr(self, 'last_file', None)
            if (l.get('isMacroArgExpansion', False) or e.get('isMacroArgExpansion', False)) and not self.in_define(sf, s.get('offset')):
                self.cur_file = sf
                return s.get('offset'), s.get('tokLen', 0), False
            self.spell_file = sf
            self.cur_file = ef
            return e.get('offset'), e.get('tokLen', 0), True
        if 'file' in l: self.last_file = l['file']
        self.cur_file = getattr(self, 'last_file', None)
        return l.get('offset'), l.get('tokLen', 0), False
    def in_define(self, f, off):
        # Una macro dentro del argumento de otra se escribe en el cuerpo de su #define: ahí no se puede editar.
        if not f or off is None: return True
        ranges = self.define_ranges.get(f)
        if ranges is None:
            try: text = self.src(f)
            except OSError: text = ''
            ranges = [(m.start(), m.end()) for m in re.finditer(r'^[ \t]*#[ \t]*define\b(?:[^\n\\]|\\.|\\\n)*', text, re.M | re.S)]
            self.define_ranges[f] = ranges
        return any(a <= off < b for a, b in ranges)
    def in_scope(self, f):
        if not f: return False
        f = os.path.realpath(f)
        return f == self.main or any(f.startswith(r + os.sep) for r in self.roots)
    def src(self, f):
        if f not in self.body: self.body[f] = open(f, 'rb').read().decode('latin-1')
        return self.body[f]
    def edit(self, f, start, end, text):
        f = os.path.realpath(f)
        text = text.replace(' : : ', '::')
        key = (start, end)
        e = self.fe[f].edits
        if key in e and start == end:
            # Inserciones en la misma posición: se acumulan, la exterior primero.
            e[key] = e[key] + text
            return
        if key in e and e[key] != text: self.stats['conflict_edit'] += 1
        e[key] = text
    # recorrido
    def walk_top(self, ast):
        for n in ast.get('inner', []):
            self.update_file(n)
            self.walk(n, None)
    def update_file(self, n):
        self.loc(n.get('loc')); r = n.get('range', {})
        self.loc(r.get('begin')); self.loc(r.get('end'))
    def rng(self, n):
        r = n.get('range', {})
        b, bl, bm = self.loc(r.get('begin')); fb = self.cur_file
        e, el, em = self.loc(r.get('end')); fe = self.cur_file
        return b, (e + el if e is not None else None), fb, fe, bm or em
    def walk(self, n, parent, ctx=None):
        k = n.get('kind')
        l = n.get('loc', {})
        if n.get('isImplicit') and k not in ('ImplicitCastExpr',): 
            self.track(n); return
        # Para saber el fichero: cada nodo actualiza cur_file en orden del JSON.
        name_off, name_len, name_macro = self.loc(l)
        nf = self.cur_file
        b, e, fb, fe, m = self.rng(n)
        if n.get('id') in self.skip_ids:
            self.track(n); return
        if k in ('RecordDecl', 'CXXRecordDecl', 'ClassTemplateSpecializationDecl', 'ClassTemplatePartialSpecializationDecl') and n.get('inner'):
            if n.get('tagUsed') == 'union': self.fix_union(n)
            self.reverse_bitfields(n)
        rec = self.recs.get(n.get('id')) if k in ('CXXRecordDecl', 'ClassTemplateSpecializationDecl', 'ClassTemplatePartialSpecializationDecl') else None
        if k in ('CXXMethodDecl', 'CXXConstructorDecl', 'CXXDestructorDecl') and self.in_scope(nf) and n.get('id') in self.member_rec:
            self.lower_member(n, k, name_off, name_len, name_macro, b, e, nf, m)
        elif k == 'CXXDeleteExpr':
            if self.in_scope(fb): self.lower_delete(n, b, e, fb, m)
        elif k == 'MemberExpr':
            if self.vmethods: self.lower_member_expr(n, parent); self.loc(n.get('range', {}).get('begin'))
        if k == 'FieldDecl' and parent is not None and self.in_scope(nf) and e is not None:
            pr = self.recs.get(parent.get('id'))
            if pr is not None and pr.base_texts and pr.first_field is n and self.lang != 'c':
                if n.get('name') and not m: self.edit(nf, e, e, self.base_align_attr(pr)); self.stats['base_align_attr'] += 1
                else: self.stats['base_align_attr_skip'] += 1
        if rec is not None and self.lang != 'c' and e is not None and self.in_scope(fe) and not m:
            for t_ in self.class_tail(rec): self.edit(fe, e - 1, e - 1, ' ' + t_ + ' ')
        if k in ('FieldDecl', 'VarDecl', 'ParmVarDecl', 'TypedefDecl', 'FunctionDecl', 'CXXMethodDecl', 'TypeAliasDecl'):
            if self.in_scope(nf): self.decl(n, k, name_off, name_len, name_macro, b, e, nf, m, parent)
        elif k == 'CXXConversionDecl':
            if self.in_scope(nf) and not m and not name_macro: self.conversion(n, b, nf)
        elif k == 'NonTypeTemplateParmDecl':
            if self.in_scope(nf) and not m: self.template_value(n, b, e, nf)
        elif k in ('ImplicitCastExpr', 'CStyleCastExpr', 'CXXFunctionalCastExpr', 'CXXStaticCastExpr', 'CXXReinterpretCastExpr', 'CXXConstCastExpr'):
            if self.in_scope(fb): self.cast(n, k, b, e, fb, m, parent)
        elif k == 'UnaryExprOrTypeTraitExpr':
            if self.in_scope(fb) and 'argType' in n: self.sizeof(n, b, e, fb, m)
        elif k == 'VAArgExpr':
            if self.in_scope(fb): self.vaarg(n, b, e, fb, m)
        elif k == 'CallExpr':
            if self.in_scope(fb): self.call(n)
        elif k == 'ConditionalOperator':
            if self.in_scope(fb) and not m: self.conditional(n)
        if k in ('FunctionTemplateDecl', 'ClassTemplateDecl', 'VarTemplateDecl'):
            seen_pattern = False
            for c in n.get('inner', []):
                ck = c.get('kind', '')
                if ck in ('FunctionDecl', 'CXXMethodDecl', 'CXXConstructorDecl', 'CXXDestructorDecl', 'CXXConversionDecl', 'CXXRecordDecl', 'VarDecl'):
                    if seen_pattern: self.track(c); continue
                    seen_pattern = True
                    self.walk(c, n)
                elif ck.endswith('SpecializationDecl'):
                    self.track(c)
                else:
                    self.walk(c, n)
            return
        if k in ('ClassTemplateSpecializationDecl', 'ClassTemplatePartialSpecializationDecl') and not n.get('isExplicit', True):
            self.track(n); return
        is_c = k == 'LinkageSpecDecl' and n.get('language') == 'C'
        if is_c: self.c_linkage += 1
        for c in n.get('inner', []):
            self.walk(c, n)
        if is_c: self.c_linkage -= 1
    @staticmethod
    def _bit_width(field):
        for c in field.get('inner', []):
            if 'value' in c:
                try: return int(c['value'])
                except (TypeError, ValueError): pass
        return None
    @staticmethod
    def _type_bits(ty):
        t = re.sub(r'\b(?:const|volatile|signed|unsigned)\b', ' ', ty).strip()
        if 'long long' in t: return 64
        if t in ('char', 'bool', '_Bool'): return 8
        if t in ('short', 'short int'): return 16
        return 32
    SCALAR = {'char': 1, 'signed char': 1, 'unsigned char': 1, 'bool': 1, '_Bool': 1, 'short': 2, 'unsigned short': 2, 'int': 4, 'unsigned int': 4,
              'long': 4, 'unsigned long': 4, 'float': 4, 'double': 8, 'long long': 8, 'unsigned long long': 8}
    def _field_shape(self, fld):
        """(tipo tal como se escribe, elemento, cuántos, tamaño del elemento) o None si no es escalar o array de escalares."""
        t = fld.get('type', {})
        ty = t.get('desugaredQualType', t.get('qualType', ''))
        written = t.get('qualType', '')
        m = re.fullmatch(r'(.+?) ?\[(\d+)\]', ty)
        count = int(m.group(2)) if m else 1
        elem = m.group(1) if m else ty
        bare = re.sub(r'\b(?:const|volatile)\b', ' ', elem); bare = re.sub(r'\s+', ' ', bare).strip()
        if bare not in self.SCALAR: return None
        return elem, count, self.SCALAR[bare], bool(m)
    def fix_union(self, n):
        # Una unión que solapa una palabra con sus partes depende del orden de bytes: en PPC la primera parte es la
        # alta. Para que cada parte siga solapando los mismos bits, sus desplazamientos se dan la vuelta.
        inner = n.get('inner', [])
        fields = [c for c in inner if c.get('kind') == 'FieldDecl']
        recs = {}
        for i, c in enumerate(inner):
            if c.get('kind') in ('RecordDecl', 'CXXRecordDecl') and c.get('completeDefinition', c.get('inner') is not None):
                for d in inner[i + 1:]:
                    if d.get('kind') == 'FieldDecl':
                        q = d.get('type', {}).get('qualType', '')
                        if 'unnamed' in q or 'anonymous' in q or c.get('name') and c['name'] in q: recs[d.get('id')] = c
                        break
        shapes = {}; size = 0
        for fld in fields:
            r = recs.get(fld.get('id'))
            if r is not None:
                lay = self._inline_layout(r)
                if lay is None:
                    if not any(x.get('isBitfield') for x in r.get('inner', [])): self.stats['union_struct_sin_forma'] += 1
                    shapes[fld.get('id')] = None; continue
                shapes[fld.get('id')] = ('rec', r, lay); size = max(size, lay[1]); continue
            sh = self._field_shape(fld)
            shapes[fld.get('id')] = sh
            if sh: size = max(size, sh[1] * sh[2])
            else:
                q = fld.get('type', {}).get('qualType', '')
                if not any(c in q for c in '*('): self.stats['union_tipo_con_nombre'] += 1
        if size not in (2, 4, 8): return
        for fld in fields:
            sh = shapes.get(fld.get('id'))
            if not sh: continue
            if sh[0] == 'rec':
                self.flip_struct(sh[1], sh[2], size)
            elif sh[3] and sh[1] * sh[2] == size and sh[1] > 1:
                self.flip_array(fld, sh)
            elif not sh[3] and sh[1] * sh[2] < size:
                self.wrap_scalar(fld, sh, size)
    def _inline_layout(self, r):
        off = 0; align = 1; out = []
        for x in r.get('inner', []):
            if x.get('kind') != 'FieldDecl': continue
            if x.get('isBitfield'): return None
            sh = self._field_shape(x)
            if not sh: return None
            elem, count, z, arr = sh
            off = (off + z - 1) // z * z
            out.append((x.get('name'), elem, count, z, arr, off))
            off += z * count; align = max(align, z)
        if not out: return None
        return out, (off + align - 1) // align * align
    def _plain_range(self, n):
        rb = n.get('range', {}).get('begin', {}); re_ = n.get('range', {}).get('end', {})
        if 'spellingLoc' in rb or 'spellingLoc' in re_: return None
        saved = (getattr(self, 'last_file', None), self.cur_file)
        b, _, _ = self.loc(rb); f = self.cur_file
        e, el, _ = self.loc(re_)
        self.last_file, self.cur_file = saved
        if b is None or e is None or not f or not self.in_scope(f): return None
        return f, b, e, el
    def flip_struct(self, r, lay, size):
        g = self._plain_range(r)
        if not g: self.stats['union_en_macro'] += 1; return
        f, b, e, el = g
        s = self.src(f)
        lb = s.find('{', b)
        if lb < 0 or lb > e: return
        fields = sorted(lay[0], key=lambda x: size - x[5] - x[3] * x[2])
        parts = []; at = 0
        for i, (name, elem, count, z, arr, off) in enumerate(fields):
            where = size - off - z * count
            if where > at: parts.append(f'char w3d_gap{i}[{where - at}];')
            parts.append(f'{elem} {name}[{count}];' if arr else f'{elem} {name};')
            at = where + z * count
        self.edit(f, lb + 1, e, ' ' + ' '.join(parts) + ' ')
        self.skip_ids.add(r.get('id'))
        self.stats['union_struct'] += 1
    def flip_array(self, fld, sh):
        g = self._plain_range(fld)
        if not g: self.stats['union_en_macro'] += 1; return
        f, b, e, el = g
        s = self.src(f)
        end = s.find(';', e)
        if end < 0: return
        self.edit(f, b, end, f"w3d::be_array<{sh[0]}, {sh[1]}> {fld.get('name')}")
        self.stats['union_array'] += 1
    def wrap_scalar(self, fld, sh, size):
        g = self._plain_range(fld)
        if not g: self.stats['union_en_macro'] += 1; return
        f, b, e, el = g
        s = self.src(f)
        end = s.find(';', e)
        if end < 0: return
        self.edit(f, b, end + 1, f"struct {{ char w3d_gap_{fld.get('name')}[{size - sh[2]}]; {sh[0]} {fld.get('name')}; }};")
        self.stats['union_escalar'] += 1
    def reverse_bitfields(self, n):
        # PPC asigna los campos de bits desde el bit alto y ARM desde el bajo. Las unidades leen la palabra
        # con máscaras (& 0x40000000), así que cada grupo se escribe al revés dentro de su palabra, con el
        # hueco delante: el mismo valor de palabra en los dos procesadores.
        inner = n.get('inner', [])
        i = 0
        while i < len(inner):
            if not (inner[i].get('kind') == 'FieldDecl' and inner[i].get('isBitfield')):
                i += 1; continue
            j = i
            while j < len(inner) and inner[j].get('kind') == 'FieldDecl' and inner[j].get('isBitfield'): j += 1
            self.rewrite_bit_run(inner[i:j], inner[j] if j < len(inner) else None, n)
            i = j
    def _room_before_run(self, first, record):
        """Bits libres en la palabra de 32 donde empieza el grupo, o None si la disposición previa no es segura."""
        if record.get('bases'): return None
        bit = 0
        for fld in record.get('inner', []):
            if fld is first: break
            if fld.get('kind') != 'FieldDecl': continue
            if fld.get('isBitfield'):
                w = self._bit_width(fld)
                if w is None: return None
                bit += w; continue
            ty = fld.get('type', {}).get('qualType', '')
            m = re.fullmatch(r'(.*?)\s*\[(\d+)\]', ty)
            count = int(m[2]) if m else 1
            base = m[1] if m else ty
            if '*' in base or 'Ptr32' in base: size = 32
            else:
                try: size = self._type_bits(base)
                except Exception: return None
            if size not in (8, 16, 32, 64): return None
            bit = (bit + size - 1) // size * size + size * count
        rest = (32 - bit % 32) % 32
        return rest or None
    def rewrite_bit_run(self, run, following, record):
        rb = run[0].get('range', {}).get('begin', {}); re_ = run[-1].get('range', {}).get('end', {})
        if 'spellingLoc' in rb or 'spellingLoc' in re_: self.stats['bitfield_in_macro'] += 1; return
        saved = (getattr(self, 'last_file', None), self.cur_file)
        b, _, _ = self.loc(rb); f = self.cur_file
        e, el, _ = self.loc(re_)
        self.last_file, self.cur_file = saved
        if b is None or e is None or not f or not self.in_scope(f): return
        s = self.src(f)
        semi = s.find(';', e)
        if semi < 0: return
        units = []; cur = None
        for fld in run:
            w = self._bit_width(fld)
            if w is None: self.stats['bitfield_no_width'] += 1; return
            ty = fld.get('type', {}).get('qualType', 'unsigned int')
            ty = re.sub(r'\blong\b(?! long)', 'int', ty)
            size = self._type_bits(ty)
            if w == 0: cur = None; continue
            if cur is None or cur['size'] != size or cur['used'] + w > size:
                cur = dict(size=size, used=0, type=ty, fields=[]); units.append(cur)
            cur['fields'].append((ty, fld.get('name'), w)); cur['used'] += w
        # Si delante hay campos pequeños, el primer grupo solo dispone del resto de esa palabra: GCC no abre otra.
        room = self._room_before_run(run[0], record)
        if room in (8, 16) and units and units[0]['size'] == 32 and units[0]['used'] <= room:
            u0 = units[0]; u0['size'] = room
            small = 'unsigned char' if room == 8 else 'unsigned short'
            u0['type'] = small
            u0['fields'] = [(small if t_.startswith('unsigned') or t_ == 'int' else t_, n_, w_) for t_, n_, w_ in u0['fields']]
            self.stats['bitfield_tras_campos'] = self.stats.get('bitfield_tras_campos', 0) + 1
        # Si detrás viene un campo pequeño que cabe en la misma palabra, el último grupo solo ocupa sus bytes.
        if following is not None and following.get('kind') == 'FieldDecl' and units:
            last = units[-1]
            fty = re.sub(r'\[.*\]', '', following.get('type', {}).get('qualType', ''))
            if '*' not in fty and self._type_bits(fty) < last['size'] and last['used'] < last['size']:
                nbytes = (last['used'] + 7) // 8
                bits = 8 if nbytes == 1 else 16
                if bits < last['size'] and last['used'] <= bits:
                    last['size'] = bits
                    last['type'] = 'unsigned char' if bits == 8 else 'unsigned short'
                    last['fields'] = [(('unsigned char' if bits == 8 else 'unsigned short') if t_.startswith('unsigned') or t_ == 'int' else t_, n_, w_) for t_, n_, w_ in last['fields']]
        parts = []
        for u in units:
            rest = u['size'] - u['used']
            if rest: parts.append(f"{u['type']} :{rest};")
            for t_, n_, w_ in reversed(u['fields']):
                parts.append(f"{t_} {n_ or ''}:{w_};")
        self.edit(f, b, semi + 1, ' '.join(parts))
        self.stats['bitfield_runs'] += 1
    def track(self, n):
        self.update_file(n)
        for c in n.get('inner', []): self.track(c)
    # declaraciones
    def decl(self, n, k, off, ln, mac, b, e, f, m, parent):
        ty = n.get('type', {}).get('qualType', '')
        name = n.get('name', '')
        if not ty or off is None or b is None: return
        if name.startswith('operator ') and ('new' in name or 'delete' in name): return
        if parent is not None and parent.get('kind') in ('FunctionDecl', 'CXXMethodDecl') and parent.get('name', '').startswith('operator ') and ('new' in parent['name'] or 'delete' in parent['name']): return
        if mac: self.stats['decl_in_macro'] += 1; return
        # #define F(name) char *name(...): el nombre viene de un argumento pero el tipo está en el #define.
        rb = n.get('range', {}).get('begin', {})
        if 'spellingLoc' in rb and not rb.get('isMacroArgExpansion') and not rb.get('expansionLoc', {}).get('isMacroArgExpansion') and b is not None and re.match(r'\w+\s*\(', self.src(f)[b:b + 80]):
            self.stats['decl_begin_in_macro'] += 1; return
        # #define F(T, a, b) T *a(...): tipo y nombre son argumentos distintos de la misma macro.
        if 'spellingLoc' in rb and b is not None and off is not None and off > b and re.search(r',', self.src(f)[b:off]) and self.src(f)[b:off].count('(') == self.src(f)[b:off].count(')'):
            self.stats['decl_across_macro_args'] += 1; return
        # Punteros a miembro: firma convertida, puntero del anfitrión. En un campo ocupa 16 B frente a 8 B en GC: se anota.
        if '::*' in ty:
            self.stats['member_pointer'] += 1
            if k == 'FieldDecl': self.pmf_fields.append(f'{os.path.relpath(f, os.path.dirname(self.main))}:{name}: {ty}')
        s = self.src(f)
        if name and k == 'ParmVarDecl' and s[off:off + len(name)] != name:
            # Especialización explícita: el AST copia el nombre del patrón, el fichero no lo tiene.
            # La posición "del nombre" es la del token siguiente (la coma o el paréntesis).
            name = ''; e = off
        tag_close = None
        spec_all = s[b:off] if b is not None and off is not None and off > b else ''
        if '{' in spec_all and k in ('FieldDecl', 'VarDecl', 'TypedefDecl') and '*' in ty:
            # struct V { ... } *x: la definición se queda y solo cambia el declarador.
            open_at = b + spec_all.index('{'); d = 0; j = open_at
            while j < off:
                if s[j] == '{': d += 1
                elif s[j] == '}':
                    d -= 1
                    if d == 0: tag_close = j; break
                j += 1
        if 'unnamed' in ty or 'anonymous' in ty or '(lambda' in ty:
            if '*' not in ty: return
            mk = re.match(r'\s*(?:typedef\s+|static\s+|extern\s+|const\s+|volatile\s+)*(struct|union)\s*\{', spec_all)
            if tag_close is None or not mk or '(lambda' in ty:
                self.problems.append(f'puntero con tipo sin nombre: {f}:{off}: {ty}'); return
            aname = f'w3d_anon_{b}'
            self.edit(f, b + mk.end(1), b + mk.end(1), ' ' + aname)
            ty = re.sub(r'(struct|union)\s*\((?:unnamed|anonymous)[^)]*\)', aname, ty)
        try: t = parse_type(ty)
        except Exception as ex:
            self.problems.append(f'tipo no analizable {ty}: {ex}'); return
        if k == 'FunctionDecl' and self.lang == 'c' and name and s[off + ln:off + ln + 40].lstrip().startswith('('):
            # K&R y sin prototipo: en C++ () significa "sin argumentos".
            i_ = s.index('(', off + ln); j_ = i_; d_ = 0
            while j_ < len(s):
                if s[j_] == '(': d_ += 1
                elif s[j_] == ')':
                    d_ -= 1
                    if d_ == 0: break
                j_ += 1
            after = s[j_ + 1:j_ + 200].lstrip()
            if s[i_ + 1:j_].strip() == '' and not after.startswith('{') and n.get('id'):
                self.noproto[n['id']] = (f, i_, j_ + 1)
            elif isinstance(t, Fn) and s[i_ + 1:j_].strip() and after[:1] not in ('{', ';', ',', ')', '_', '') and any(c.get('kind') == 'CompoundStmt' for c in n.get('inner', [])):
                brace = s.index('{', j_)
                parms = [c for c in n.get('inner', []) if c.get('kind') == 'ParmVarDecl']
                txt = []
                for c in parms:
                    try: txt.append(rt(parse_type(c.get('type', {}).get('qualType', 'int')), c.get('name', '')))
                    except Exception: pass
                if len(txt) == len(parms):
                    self.edit(f, i_, brace, '(' + ', '.join(txt) + ')\n')
                    self.stats['knr'] += 1
        if k in ('FunctionDecl', 'CXXMethodDecl'):
            if not isinstance(t, Fn): return
            group = self.groups.get((f, b))
            if group is None: self.groups[(f, b)] = (off, ty)
            if not has_ptr(t.ret):
                if group is not None and has_ptr(parse_type(group[1]).ret if isinstance(parse_type(group[1]), Fn) else Base('')):
                    # int *f(), g(): el segundo declarador no devuelve puntero y lleva su propio tipo.
                    c = s.rfind(',', 0, off)
                    self.edit(f, c, off, '; ' + self.storage(s[b:group[0]]) + rt(t.ret) + ' ')
                return
            if group is not None:
                # T *f(), *g(): el tipo compartido ya no vale para el segundo declarador.
                c = s.rfind(',', 0, off)
                self.edit(f, c, off, '; ' + self.storage(s[b:group[0]]) + rt(t.ret) + ' ')
                self.stats['split_fn'] += 1
                return
            # template <...> fuera de la clase forma parte del rango de la declaración y se conserva.
            tp = 0
            while True:
                mt = re.compile(r'\s*template\s*<').match(s, b + tp)
                if not mt: break
                j_ = mt.end(); d_ = 1
                while j_ < off and d_:
                    if s[j_] == '<': d_ += 1
                    elif s[j_] == '>': d_ -= 1
                    j_ += 1
                tp = j_ - b
            b = b + tp
            spec = s[b:off]
            prefix = self.storage(spec)
            q = re.search(r'((?:[A-Za-z_]\w*(?:<[^<>]*>)?\s*::\s*)+)$', spec)
            self.edit(f, b, off, prefix + rt(t.ret) + ' ' + (q.group(1) if q else ''))
            self.stats['ret'] += 1
            return
        in_for = k == 'VarDecl' and re.search(r'\bfor\s*\($', s[max(0, b - 40):b].rstrip() + '') is not None
        if in_for and parent is not None and sum(1 for c in parent.get('inner', []) if c.get('kind') == 'VarDecl') > 1:
            # for(int *p=x,n=4;...) no admite dos tipos: las locales del bucle siguen siendo punteros reales.
            # Lo que apuntan sí conserva la forma de la memoria: T **p pasa a Ptr32<T> *p.
            self.stats['for_local_host'] += 1
            if isinstance(t, Ptr) and has_ptr(t.to):
                first = self.groups.get((f, b))
                if first is None:
                    self.groups[(f, b)] = (off, ty)
                    self.edit(f, b, off, rt(t.to) + ' *')
                else:
                    self.edit(f, s.rfind(',', 0, off) + 1, off, '*')
            return
        if k == 'ParmVarDecl' and parent is not None and parent.get('id') in self.ftmpl_ids and isinstance(t, Ptr) and not isinstance(t.to, Fn) \
                and self.mentions_tparam(t.to, self.ftmpl_ids[parent['id']]):
            # Plantilla de función: T* se deduce de T*, como el original. T** se queda como Ptr32<T>*.
            if name: self.edit(f, b, self.declarator_end(s, off + ln, s[b:off].count('(') - s[b:off].count(')')), rt(t.to) + ' *' + name)
            else:
                eq = s.find('=', b, e) if e is not None else -1
                self.edit(f, b, eq if eq >= 0 else e, rt(t.to) + ' *' + (' ' if eq >= 0 else ''))
            self.stats['template_host_param'] += 1
            return
        if k == 'ParmVarDecl' and parent is not None and parent.get('kind') == 'CXXConstructorDecl' and isinstance(t, Ptr) \
                and sum(1 for c in parent.get('inner', []) if c.get('kind') == 'ParmVarDecl') == 1 and not isinstance(t.to, Fn):
            # Constructor de conversión: Key k = 0 y Key k = "x" necesitan un puntero real. Se añade la forma con Ptr32.
            if has_ptr(t.to):
                self.edit(f, b, off, rt(t.to) + ' *')
            pb = parent.get('range', {}).get('begin', {}).get('offset')
            cname = parent.get('name')
            spec_p = s[pb:pb + 40] if pb is not None else ''
            if pb is not None and cname and 'expansionLoc' not in parent.get('range', {}).get('begin', {}) and '::' not in s[pb:s.find('(', pb)] and parent.get('id') not in self.ctor_done:
                self.ctor_done.add(parent.get('id'))
                base = rt(t.to) + ' *'
                expl = 'explicit ' if spec_p.lstrip().startswith('explicit') else ''
                if self.c_linkage:
                    self.edit(f, pb, pb, f'{expl}{cname}({rt(t)} w3d_p) : {cname}(({base})w3d_p.get()) {{}}\n ')
                else:
                    self.edit(f, pb, pb, f'template <class W3dU> {expl}{cname}(Ptr32<W3dU> w3d_p) : {cname}(({base})w3d_p.get()) {{}}\n ')
                self.stats['ctor_ptr32'] += 1
            return
        if k == 'ParmVarDecl' and parent is not None and str(parent.get('name', '')).startswith('operator') and isinstance(t, Ptr) and not isinstance(t.to, Fn):
            # Operadores: String + "x" debe seguir siendo una sola conversión.
            if has_ptr(t.to): self.edit(f, b, off, rt(t.to) + ' *')
            self.stats['operator_host_param'] += 1
            pb = parent.get('range', {}).get('begin', {}).get('offset')
            if parent.get('name') == 'operator=' and parent.get('kind') == 'CXXMethodDecl' and pb is not None and 'expansionLoc' not in parent.get('range', {}).get('begin', {}) \
                    and '::' not in s[pb:s.find('(', pb)].replace('operator=', '') and parent.get('id') not in self.ctor_done and not self.c_linkage:
                self.ctor_done.add(parent.get('id'))
                base = rt(t.to) + ' *'
                self.edit(f, pb, pb, f'template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) {{ return this->operator=(({base})w3d_p.get()); }}\n ')
            return
        if not has_ptr(t):
            if k in ('VarDecl', 'FieldDecl', 'TypedefDecl') and name:
                first = self.groups.get((f, b))
                if first is None: self.groups[(f, b)] = (off, ty)
                elif has_ptr(parse_type(first[1])):
                    # int *a, b: el segundo declarador no es puntero y necesita su propio tipo.
                    c = s.rfind(',', 0, off)
                    dend = self.declarator_end(s, off + ln, 0)
                    self.edit(f, c, dend, '; ' + self.storage(s[b:first[0]].split('{')[0]) + rt(t, name))
                    self.stats['split_plain'] += 1
            return
        # Grupo con especificador compartido: int *a, b.
        if k == 'ParmVarDecl' and not name:
            # Parámetro sin nombre: solo tipo. El valor por defecto se conserva.
            eq = s.find('=', b, e) if e is not None else -1
            self.edit(f, b, eq if eq >= 0 else e, rt(t) + (' ' if eq >= 0 else '')); self.stats['parm'] += 1; return
        spec_end = off
        # Fin del declarador: tras el nombre y sufijos ) y [..]
        dend = self.declarator_end(s, off + ln, s[b:off].count('(') - s[b:off].count(')'))
        # T x(n): los paréntesis son el inicializador, no parte del declarador.
        if k == 'VarDecl' and n.get('init') == 'call' and s[b:off].count('(') == s[b:off].count(')'): dend = off + ln
        first = None if k == 'ParmVarDecl' else self.groups.get((f, b))
        plain = s[b:off] if tag_close is None else s[b:b + spec_all.index('{')]
        if first is None:
            self.groups[(f, b)] = (off, ty)
            prefix = self.storage(plain)
            if tag_close is not None:
                self.edit(f, tag_close + 1, dend, '; ' + prefix + rt(t, name))
                self.stats['inline_tag'] += 1
            else:
                self.edit(f, b, dend, prefix + rt(t, name))
        else:
            # Segundo declarador: buscar la coma anterior.
            c = s.rfind(',', 0, off)
            prefix = self.storage(plain if tag_close is not None else s[b:first[0]])
            self.edit(f, c, dend, '; ' + prefix + rt(t, name))
            self.stats['split_decl'] += 1
        self.stats[k] += 1
    def storage(self, spec):
        out = []
        m = re.match(r'\s*(LUA_API|LUALIB_API|LUAI_FUNC|LUAI_DATA|ZEXPORT|ZEXTERN|EXPORT|LOCAL|FAR|_CONST|_DEFUN)\b', spec)
        if m: out.append(m.group(1))
        for w in ('extern', 'static', 'register', 'inline', '__inline__', '__inline', 'typedef', 'mutable', 'explicit', 'friend'):
            if re.search(r'(^|[\s"])' + w + r'\b', spec): out.append(w)
        if re.search(r'extern\s+"C(\+\+)?"', spec):
            m = re.search(r'extern\s+"C(\+\+)?"', spec); out = [m.group(0)] + [w for w in out if w != 'extern']
        return ' '.join(out) + (' ' if out else '')
    def declarator_end(self, s, i, opened=0):
        """Avanza desde el fin del nombre por ), [...] y (args) de punteros a función."""
        n = len(s)
        while True:
            j = i
            while j < n and s[j] in ' \t\r\n': j += 1
            if j >= n: return i
            c = s[j]
            if c == '[' or c == '(':
                d = 0; o = c; x = ']' if c == '[' else ')'
                while j < n:
                    if s[j] == o: d += 1
                    elif s[j] == x:
                        d -= 1
                        if d == 0: break
                    j += 1
                i = j + 1
                continue
            if c == ')' and opened > 0:
                opened -= 1
                i = j + 1
                continue
            return i
    # conversiones
    def cast(self, n, k, b, e, f, m, parent=None):
        ck = n.get('castKind')
        inner = n.get('inner', [])
        sub = inner[0] if inner else None
        if ck in ('IntegralToPointer', 'PointerToIntegral'):
            w = 'w3d::G' if ck == 'IntegralToPointer' else 'w3d::H'
            if sub is None: return
            sb, se, sf, _, sm = self.rng(sub)
            if sb is None or se is None or not self.in_scope(sf): return
            if sm:
                # Argumento que es una llamada a macro entera: se envuelve la llamada.
                span = self.macro_span(sub, sf, parent)
                if span is None: self.stats['conv_in_macro:' + ck] += 1; return
                sb, se = span
            if (sf, sb, se, w) not in self.wrapped:
                # Un argumento de macro usado dos veces aparece dos veces en el AST con la misma posición.
                self.wrapped.add((sf, sb, se, w))
                self.edit(sf, sb, sb, w + '(')
                self.edit(sf, se, se, ')')
                self.stats[ck] += 1
        if k != 'ImplicitCastExpr' and not m:
            ty = n.get('type', {}).get('qualType', '')
            try: t = parse_type(ty)
            except Exception: return
            need = False
            if isinstance(t, Ptr):
                if isinstance(t.to, Fn) or has_ptr(t.to): need = True
            elif isinstance(t, Base) and has_ptr(t): need = True
            if isinstance(t, Ptr): need = True
            if need and k == 'CStyleCastExpr':
                s = self.src(f)
                # El tipo va entre el primer '(' y su cierre.
                if s[b] == '(':
                    d = 0; j = b
                    while j < len(s):
                        if s[j] == '(': d += 1
                        elif s[j] == ')':
                            d -= 1
                            if d == 0: break
                        j += 1
                    self.edit(f, b, j + 1, '(' + rt(t) + ')')
                    self.stats['cast_type'] += 1
    def conversion(self, n, b, f):
        # operator Item*(): Slot a Ptr32<Item> serían dos conversiones; se añade la directa.
        ty = n.get('type', {}).get('qualType', '')
        m_ = re.match(r'(.+?\*)\s*\(\)', ty)
        if not m_: return
        s = self.src(f)
        spec = s[b:b + 80]
        if '::' in spec.split('(')[0]: return
        try: t = parse_type(m_.group(1))
        except Exception: return
        if not isinstance(t, Ptr) or isinstance(t.to, Fn): return
        cv = ' const' if ') const' in ty else ''
        base = rt(t.to) + ' *'
        self.edit(f, b, b, f'operator {rt(t)}(){cv} {{ return ({base})this->operator {m_.group(1)}(); }}\n ')
        self.stats['conversion_ptr32'] += 1
    def template_value(self, n, b, e, f):
        # template <R (*Cast)(A)>: el tipo de la función sigue la forma convertida; el puntero a función es real.
        ty = n.get('type', {}).get('qualType', '')
        name = n.get('name', '')
        try: t = parse_type(ty)
        except Exception: return
        if isinstance(t, Ptr) and isinstance(t.to, Fn) and name:
            ps = ', '.join(rt(p) for p in t.to.params)
            self.edit(f, b, e + 0, f'{rt(t.to.ret)} (*{name})({ps})')
            self.stats['template_value'] += 1
    def macro_span(self, sub, f, parent=None):
        r = sub.get('range', {}); bl = r.get('begin', {}); el = r.get('end', {})
        if 'expansionLoc' not in bl: return None
        ob = bl['expansionLoc'].get('offset')
        if ob is None: return None
        if 'expansionLoc' not in el and 'offset' in el:
            # Empieza en una macro y acaba fuera: M2C_FIELD(...)(x).
            return ob, el['offset'] + el.get('tokLen', 1)
        oe = el['expansionLoc'].get('offset')
        if ob != oe: return None
        # Si el padre también está dentro de la misma macro, la conversión es interna a ella.
        pr = (parent or {}).get('range', {}); pb = pr.get('begin', {}); pe = pr.get('end', {})
        if pb.get('expansionLoc', {}).get('offset') == ob and pe.get('expansionLoc', {}).get('offset') == ob: return None
        s = self.src(f)
        m = re.compile(r'[A-Za-z_]\w*').match(s, ob)
        if not m or m.group(0).startswith('va_') or m.group(0) == 'assert': return None
        j = m.end()
        while j < len(s) and s[j] in ' \t': j += 1
        if j >= len(s) or s[j] != '(': return ob, m.end()
        d = 0
        while j < len(s):
            if s[j] == '(': d += 1
            elif s[j] == ')':
                d -= 1
                if d == 0: return ob, j + 1
            j += 1
        return None
    def conditional(self, n):
        # cond ? Ptr32<T> : T* es ambiguo en C++: las dos ramas pasan a T*.
        ty = n.get('type', {}).get('qualType', '')
        if '*' not in ty: return
        for a in n.get('inner', [])[1:]:
            if a.get('castKind') == 'NullToPointer': continue
            sb, se, sf, _, sm = self.rng(a)
            if sb is None or se is None or sm or not self.in_scope(sf): continue
            if (sf, sb, se, 'R') in self.wrapped: continue
            self.wrapped.add((sf, sb, se, 'R'))
            self.edit(sf, sb, sb, 'w3d::R('); self.edit(sf, se, se, ')')
            self.stats['cond_ptr'] += 1
    @staticmethod
    def callee_ref(cal):
        while cal.get('kind') in ('ImplicitCastExpr', 'ParenExpr', 'CStyleCastExpr') and cal.get('inner'): cal = cal['inner'][0]
        return cal if cal.get('kind') == 'DeclRefExpr' else None
    def call(self, n):
        inner = n.get('inner', [])
        if not inner: return
        cal = inner[0]
        ref = self.callee_ref(cal)
        if ref is not None:
            rd = ref.get('referencedDecl', {})
            if rd.get('id') in self.noproto and rd.get('id') not in self.noproto_args and len(inner) > 1:
                tys = []
                for a_ in inner[1:]:
                    ty_ = a_.get('type', {}).get('desugaredQualType') or a_.get('type', {}).get('qualType', 'int')
                    try: tys.append(rt(parse_type(ty_)))
                    except Exception: tys.append('int')
                self.noproto_args[rd['id']] = tys
            if ref.get('foundReferencedDecl', {}).get('kind') == 'FunctionTemplateDecl':
                # Las plantillas deducen T desde T*, como el original: el argumento tiene que ser puntero real.
                self.wrap_template_args(inner, ref.get('referencedDecl', {}).get('name'))
        elif cal.get('kind') in ('UnresolvedLookupExpr', 'UnresolvedMemberExpr', 'CXXDependentScopeMemberExpr', 'ImplicitCastExpr'):
            # Llamada dependiente dentro de una plantilla: se conoce el nombre, no la sobrecarga.
            c_ = cal
            while c_.get('kind') == 'ImplicitCastExpr' and c_.get('inner'): c_ = c_['inner'][0]
            nm = c_.get('name') or c_.get('member')
            if nm in self.tmpl_ptr_pos: self.wrap_template_args(inner, nm)
        if len(inner) < 2: return
        cty = cal.get('type', {}).get('qualType', '')
        if '...' not in cty: return
        try:
            ft = parse_type(cty)
            if isinstance(ft, Ptr): ft = ft.to
            nfixed = len(ft.params)
        except Exception: return
        for a in inner[1 + nfixed:]:
            ty = a.get('type', {}).get('qualType', '')
            if '*' not in ty and '[' not in ty: continue
            sb, se, sf, _, sm = self.rng(a)
            if sb is None or se is None or not self.in_scope(sf): continue
            if sm: self.stats['va_in_macro'] += 1; continue
            if (sf, sb, se, 'VA') in self.wrapped: continue
            self.wrapped.add((sf, sb, se, 'VA'))
            self.edit(sf, sb, sb, 'w3d::VA(')
            self.edit(sf, se, se, ')')
            self.stats['va_arg_ptr'] += 1
    def wrap_template_args(self, inner, name):
        nargs = len(inner) - 1
        positions = set()
        for lo, hi, pos in self.tmpl_ptr_pos.get(name, []):
            if lo <= nargs <= hi: positions |= pos
        for i_, a_ in enumerate(inner[1:]):
            if i_ not in positions or a_.get('castKind') == 'NullToPointer': continue
            sb, se, sf, _, sm = self.rng(a_)
            if sb is None or se is None or not self.in_scope(sf): continue
            if sm: self.stats['template_arg_in_macro'] += 1; continue
            if (sf, sb, se, 'R') in self.wrapped: continue
            self.wrapped.add((sf, sb, se, 'R'))
            self.edit(sf, sb, sb, 'w3d::R('); self.edit(sf, se, se, ')')
            self.stats['template_arg'] += 1
    def sizeof(self, n, b, e, f, m):
        if m: return
        ty = n['argType'].get('qualType', '')
        if '*' not in ty or 'unnamed' in ty: return
        try: t = parse_type(ty)
        except Exception: return
        s = self.src(f); o = s.find('(', b, e)
        if o < 0: return
        self.edit(f, o, e, '(' + rt(t) + ')')
        self.stats['sizeof'] += 1
    def vaarg(self, n, b, e, f, m):
        ty = n.get('type', {}).get('qualType', '')
        if '*' not in ty: return
        # va_arg es una macro: su tipo se busca en el texto expandido del fichero.
        s = self.src(f)
        lo = b if b is not None else 0
        m2 = re.compile(r'va_arg\s*\(').search(s, lo)
        if not m2 or m2.start() - lo > 2000: self.stats['vaarg_macro'] += 1; return
        o = m2.end() - 1; d = 0; j = o; comma = -1
        while j < len(s):
            if s[j] == '(': d += 1
            elif s[j] == ')':
                d -= 1
                if d == 0: break
            elif s[j] == ',' and d == 1: comma = j
            j += 1
        if comma < 0: return
        self.edit(f, comma + 1, j, ' ' + render(ty))
        self.stats['vaarg'] += 1

# sizeof de un puntero en el texto (también en tipos, donde el AST no da posición): siempre 4 B.
SIZEOF_PTR = re.compile(r'\bsizeof\s*\(\s*((?:(?:const|volatile|unsigned|signed|struct|union)\s+)*[A-Za-z_]\w*)\s*\*+\s*(?:const\s*)?\)')
def rewrite_sizeof_ptr(text):
    return SIZEOF_PTR.sub(lambda m: f'sizeof(Ptr32<{m.group(1)}>)', text)

def rewrite_template_uses(text, names):
    """Nombre conocido de plantilla seguido de <...> con punteros fuera de una declaración: base, new, instanciación, macro.
    Los argumentos de una especialización parcial (template <class T> struct X<T *>) se quedan: T* sigue siendo un tipo real."""
    if not names: return text
    pat = re.compile(r'\b(' + '|'.join(sorted(map(re.escape, names), key=len, reverse=True)) + r')\s*<')
    parts = re.split(r'("(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|/\*.*?\*/|//[^\n]*)', text, flags=re.S)
    for pi in range(0, len(parts), 2):
        t = parts[pi]
        if '*' not in t: continue
        out = []; pos = 0
        for m in pat.finditer(t):
            if m.start() < pos: continue
            lead = t[max(0, m.start() - 200):m.start()]
            if re.search(r'template\s*<[^;{}]*>\s*(?:struct|class)\s+$', lead): continue
            if lead.rstrip().endswith('Ptr32<') and False: continue
            d = 0; j = m.end() - 1
            while j < len(t):
                c = t[j]
                if c in '<(': d += 1
                elif c in '>)':
                    d -= 1
                    if d == 0: break
                elif c in ';{}': j = len(t); break
                j += 1
            if j >= len(t): continue
            inner = t[m.end() - 1:j + 1]
            if '*' not in inner: continue
            new = lift_template_args(inner)
            if new != inner:
                out.append(t[pos:m.end() - 1]); out.append(new); pos = j + 1
        out.append(t[pos:])
        parts[pi] = ''.join(out)
    return ''.join(parts)

# Conversión entero<->puntero dentro de cuerpos de macro: el AST no da la posición. (T *)((a << 2) + (int)p).
MACRO_CAST_EXPR = re.compile(r'(\(\s*(?:(?:const|volatile|struct|union|unsigned)\s+)*[A-Za-z_][\w:<> ]*\s*\*+\s*\))(\s*)\(')
MACRO_INT_CAST = re.compile(r'\(\s*(int|unsigned int|unsigned|u32|s32|unsigned long|long|Size|uintptr_t|size_t)\s*\)(\s*)(\(|[A-Za-z_]\w*)')
def is_cast_context(j, i):
    # sizeof(int) (x) o f(int) x no son conversiones.
    k = i - 1
    while k >= 0 and j[k] in ' \t': k -= 1
    return k < 0 or not (j[k].isalnum() or j[k] in '_)]')
def wrap_macro_conversions(j):
    out = []; pos = 0
    for m in MACRO_INT_CAST.finditer(j):
        if m.start() < pos or not is_cast_context(j, m.start()): continue
        if m.group(3) == '(':
            d = 0; k = m.end() - 1
            while k < len(j):
                if j[k] == '(': d += 1
                elif j[k] == ')':
                    d -= 1
                    if d == 0: break
                k += 1
            if k >= len(j): continue
            # (long)(size_t)x: lo de dentro es un tipo, no una expresión.
            if re.fullmatch(r'\s*(?:(?:const|volatile|struct|union|unsigned|signed)\s+)*[A-Za-z_]\w*\s*\**\s*', j[m.end():k]) and j[k + 1:k + 2].strip()[:1] and (j[k + 1:k + 2].isalnum() or j[k + 1:k + 2] in '_('): continue
            # (int)(h).p o (int)(a)[i]: el cast no cae sobre el paréntesis.
            if j[k + 1:k + 3].lstrip()[:2] in ('->',) or j[k + 1:k + 2] in ('.', '['): continue
            out.append(j[pos:m.end() - 1] + 'w3d::AI' + j[m.end() - 1:k + 1]); pos = k + 1
        else:
            nx = j[m.end():m.end() + 2]
            if nx[:1] in ('(', ':', '[', '.') or nx == '->': continue
            out.append(j[pos:m.start(3)] + f'w3d::AI({m.group(3)})'); pos = m.end()
    out.append(j[pos:])
    j = ''.join(out)
    out = []; pos = 0
    for m in MACRO_CAST_EXPR.finditer(j):
        if m.start() < pos: continue
        d = 0; k = m.end() - 1
        while k < len(j):
            if j[k] == '(': d += 1
            elif j[k] == ')':
                d -= 1
                if d == 0: break
            k += 1
        if k >= len(j): continue
        # (T *)(h).p: el cast no cae sobre el paréntesis.
        if j[k + 1:k + 3].lstrip()[:2] == '->' or j[k + 1:k + 2] in ('.', '['): continue
        out.append(j[pos:m.end() - 1] + 'w3d::AG'); pos = m.end() - 1
    out.append(j[pos:])
    return ''.join(out)

MACRO_DECL = re.compile(r'(?<![.>\w])\b((?:const\s+)?(?:struct\s+|union\s+|unsigned\s+)?[A-Za-z_]\w*)\s*(\*+)\s*([A-Za-z_]\w*)\s*(;)')
MACRO_CAST2 = re.compile(r'\(\s*((?:const\s+)?(?:struct\s+|union\s+)?[A-Za-z_]\w*)\s*\*\s*\*\s*\)')
# T **en una lista de parámetros de un cast dentro de una macro, y T *& de un retorno.
MACRO_PP = re.compile(r'\b((?:const\s+)?(?:struct\s+|union\s+)?[A-Za-z_]\w*)\s*\*\s*\*(?=\s*[,)])')
MACRO_PREF = re.compile(r'\b((?:const\s+)?(?:struct\s+|union\s+)?[A-Za-z_]\w*)\s*\*\s*&')
def slot_macro_types(j):
    # #define FIELD(p,T,o) (*(T *)...): T puede ser 'void *', que en memoria ocupa 4 B.
    m = re.match(r'\s*#\s*define\s+\w+\(([^)]*)\)', j)
    if not m: return j
    head = m.end()
    body = j[head:]
    for p in [x.strip() for x in m.group(1).split(',') if x.strip()]:
        if not re.fullmatch(r'[A-Za-z_]\w*', p): continue
        body = re.sub(r'\(\s*' + p + r'\s*\*\s*\)', f'(w3d::slot_t<{p}> *)', body)
        body = re.sub(r'\bPtr32<' + p + r'>', f'Ptr32<w3d::slot_t<{p}>>', body)
        body = re.sub(r'\bsizeof\s*\(\s*' + p + r'\s*\)', f'sizeof(w3d::slot_t<{p}>)', body)
        # ((T)(*x)): T es un tipo si tras el paréntesis sigue una expresión, y antes no hay identificador.
        def cast_(m_, p=p, body_ref=None):
            before = m_.string[:m_.start()].rstrip()
            word = re.search(r'(\w+)$', before)
            if word and word.group(1) in ('if', 'while', 'for', 'switch', 'return', 'sizeof', 'else', 'do'): return m_.group(0)
            return f'(w3d::slot_t<{p}>)'
        body = re.sub(r'(?<![\w)\]])\(\s*' + p + r'\s*\)(?=\s*(?:\(|[A-Za-z_]))', cast_, body)
    return j[:head] + body

def rewrite_macro_bodies(text):
    """Cuerpos de #define: 'T *x;' declara un puntero guardado y pasa a P<T>; '(T **)' a '(P<T> *)'."""
    out = []; lines = text.split('\n'); i = 0
    while i < len(lines):
        line = lines[i]
        if re.match(r'\s*#\s*define\b', line):
            blk = [line]
            while blk[-1].rstrip().endswith('\\') and i + 1 < len(lines):
                i += 1; blk.append(lines[i])
            joined = '\n'.join(blk)
            def d(m):
                t = m.group(1)
                if t in ('return', 'case', 'goto'): return m.group(0)
                for _ in m.group(2): t = f'Ptr32<{t}>'
                return f'{t} {m.group(3)}{m.group(4)}'
            def host_local(m):
                return m.group(0)
            # Una local de macro con inicializador ('T *i=(x);') puede quedarse: no se guarda.
            joined = MACRO_DECL.sub(d, joined)
            joined = MACRO_CAST2.sub(lambda m: f'(Ptr32<{m.group(1)}> *)', joined)
            joined = MACRO_PP.sub(lambda m: f'Ptr32<{m.group(1)}> *', joined)
            joined = MACRO_PREF.sub(lambda m: f'Ptr32<{m.group(1)}> &', joined)
            joined = wrap_macro_conversions(joined)
            joined = slot_macro_types(joined)
            out.append(joined)
        else:
            out.append(line)
        i += 1
    return '\n'.join(out)

VA_ARG_PTR = re.compile(r'\bva_arg\s*\(\s*([^,()]+?)\s*,\s*((?:const\s+)?(?:struct\s+|union\s+|unsigned\s+)?[A-Za-z_]\w*)\s*(\*+)\s*\)')
def rewrite_va_args(text):
    def f(m):
        t = m.group(2)
        for _ in m.group(3): t = f'Ptr32<{t}>'
        return f'va_arg({m.group(1)}, {t})'
    return VA_ARG_PTR.sub(f, text)

def rewrite_explicit_inst(text):
    # template void X::f(T *, unsigned): el AST no da nodo para esto, y los parámetros siguen la forma convertida.
    def fix(m):
        return re.sub(r'((?:const\s+)?[A-Za-z_][\w:]*(?:\s*<[^()]*?>)?)\s*\*(?=\s*[,)])', lambda q: f'Ptr32<{q.group(1)}>', m.group(0))
    return re.sub(r'^\s*template\s+(?!<)[^\n;{]*\([^\n;{]*\)\s*;', fix, text, flags=re.M)

def rewrite_reinterpret(text):
    # reinterpret_cast<T*>(x): x puede ser Ptr32, también dentro de macros.
    out = []; pos = 0
    for m in re.finditer(r'\b(?:reinterpret_cast|const_cast)\s*<', text):
        if m.start() < pos: continue
        i = m.end(); d = 1
        while i < len(text) and d:
            if text[i] == '<': d += 1
            elif text[i] == '>': d -= 1
            i += 1
        j = i
        while j < len(text) and text[j] in ' \t': j += 1
        if j >= len(text) or text[j] != '(': continue
        if text.startswith('const_cast', m.start()) and not text[m.end():i - 1].rstrip().endswith('*'): continue
        k = j; d = 0
        while k < len(text):
            if text[k] == '(': d += 1
            elif text[k] == ')':
                d -= 1
                if d == 0: break
            k += 1
        out.append(text[pos:j + 1]); out.append('w3d::R('); out.append(rewrite_reinterpret(text[j + 1:k])); out.append(')')
        pos = k
    out.append(text[pos:])
    return ''.join(out)

def rewrite_m2c_args(text):
    # M2C_FIELD(x, T **, n): el tipo está en un argumento de macro y el AST no da su posición.
    edits = []
    for m in re.finditer(r'\b\w*_FIELD\s*\(', text):
        ls = text.rfind('\n', 0, m.start()) + 1
        if text[ls:m.start()].lstrip().startswith('#'): continue
        i = m.end(); d = 0; commas = []
        while i < len(text):
            c = text[i]
            if c in '([{': d += 1
            elif c in ')]}':
                if d == 0: break
                d -= 1
            elif c == ',' and d == 0: commas.append(i)
            i += 1
        if len(commas) < 2: continue
        a, b = commas[-2] + 1, commas[-1]
        arg = text[a:b].strip()
        if arg.count('*') < 2: continue
        try: t = parse_type(arg)
        except Exception: continue
        if not isinstance(t, Ptr) or not has_ptr(t.to): continue
        edits.append((a, b, ' ' + rt(t.to) + ' *'))
    for a, b, r in sorted(edits, reverse=True): text = text[:a] + r + text[b:]
    return text

def apply_edits(src, edits):
    es = sorted(edits.items(), key=lambda kv: (kv[0][0], kv[0][1]))
    out = []; pos = 0; dropped = 0
    for (a, b), t in es:
        if a < pos:
            dropped += 1
            continue
        out.append(src[pos:a]); out.append(t); pos = b
    out.append(src[pos:])
    return ''.join(out), dropped

CPP_KW = {'class','new','delete','this','template','typename','operator','private','public','protected','virtual','namespace','try','catch','throw','friend','bool','true','false','using','export','mutable','explicit','wchar_t','nullptr','and','or','not','xor','constexpr','decltype','auto','noexcept'}
def rename_cpp_keywords(text):
    def fix(m):
        w = m.group(0)
        return w + '_' if w in CPP_KW else w
    # Respeta cadenas, caracteres y comentarios.
    parts = re.split(r'("(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|/\*.*?\*/|//[^\n]*)', text, flags=re.S)
    for i in range(0, len(parts), 2):
        parts[i] = re.sub(r'\b[A-Za-z_]\w*\b', fix, parts[i])
    return ''.join(parts)

def map_out(f, mapping):
    best = None
    for src, out in mapping:
        src = os.path.realpath(src)
        if f == src or f.startswith(src + os.sep):
            if best is None or len(src) > len(best[0]): best = (src, out)
    if best is None: return None
    return os.path.join(best[1], os.path.relpath(f, best[0]))

def lift_file(main, lang, flags, roots, mapping, patches=None, ledger_names=None):
    l = Lifter(main, lang, flags, roots, ledger_names=ledger_names).run()
    written = []
    files = set(l.fe) | {os.path.realpath(main)}
    for f in sorted(files):
        src = l.src(f) if f in l.body else open(f, 'rb').read().decode('latin-1')
        text, dropped = apply_edits(src, l.fe[f].edits)
        if dropped: l.stats['edit_dropped'] += dropped
        dst = map_out(f, mapping)
        if dst is None: l.problems.append('fuera del mapa: ' + f); continue
        if lang == 'c': text = rename_cpp_keywords(text)
        text = rewrite_reinterpret(rewrite_m2c_args(rewrite_va_args(rewrite_macro_bodies(text))))
        if lang != 'c': text = rewrite_explicit_inst(rewrite_template_uses(text, l.template_names))
        text = rewrite_sizeof_ptr(text)
        if patches:
            for pat_ in patches.get(os.path.basename(f), []) + patches.get('*', []):
                text = re.sub(pat_[0], pat_[1], text, count=pat_[2] if len(pat_) > 2 else 0, flags=re.S)
        if lang == 'c' and dst.endswith('.c'): dst = dst[:-2] + '.cpp'
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        if f == os.path.realpath(main):
            if lang == 'c': text = '#define W3D_LOOSE_C 1\n#include "w3d_ptr.h"\nextern "C" {\n#line 1 "%s"\n' % os.path.basename(f) + text + '\n}\n'
            else: text = '#include "w3d_ptr.h"\n#line 1 "%s"\n' % os.path.basename(f) + text + '\n' + '\n'.join(l.tail) + '\n'
        open(dst, 'w', encoding='latin-1').write(text)
        written.append(dst)
    # Cabeceras incluidas sin cambios: se copian para que el árbol sea autónomo.
    for f in sorted(l.included):
        dst = map_out(f, mapping)
        if dst is None or os.path.exists(dst): continue
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        text = open(f, 'rb').read().decode('latin-1')
        if lang == 'c': text = rename_cpp_keywords(text)
        text = rewrite_reinterpret(rewrite_macro_bodies(text))
        if lang != 'c': text = rewrite_template_uses(text, l.template_names)
        text = rewrite_sizeof_ptr(text)
        if patches:
            for pat_ in patches.get(os.path.basename(f), []) + patches.get('*', []):
                text = re.sub(pat_[0], pat_[1], text, count=pat_[2] if len(pat_) > 2 else 0, flags=re.S)
        open(dst, 'w', encoding='latin-1').write(text)
    return l, written

if __name__ == '__main__':
    print(render('void (*)(int, char *)', 'cb'))
    print(render('int (*[4])(void)', 'tbl'))
    print(render('struct Foo **', 'kids'))
    print(render('const char *const *', 'x'))
    print(render('int (*)[3]', 'pa'))
    print(render('char *[4]', 'pa'))
    print(render('unsigned long', 'u'))
    print(render('void *(*)(void *, unsigned long)'))
