#!/usr/bin/env python3
"""Convierte todas las fuentes admitidas del ledger a port/core/game y mide cuántas compilan.

Uso: lift_all.py [--limit N] [--no-lift] [--target arm64-apple-macos14]
Salida: port/docs-data/lift-census.json
"""
import json, os, re, subprocess, sys, collections, glob, concurrent.futures as cf, argparse, shutil
sys.path.insert(0, os.path.dirname(__file__))
from lift import lift_file
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
TMP = os.environ.get('W3D_TMP', '/tmp/w3dp')
ap = argparse.ArgumentParser(); ap.add_argument('--limit', type=int); ap.add_argument('--no-lift', action='store_true'); ap.add_argument('--target', default='arm64-apple-macos14'); ap.add_argument('--only'); ap.add_argument('--jobs', type=int, default=12); ap.add_argument('--ir', action='store_true')
a = ap.parse_args()
OUT = f'{ROOT}/port/core/game'
SKIP_PREFIX = ('build/lua', 'source/vendor/lua-5.0', 'source/vendor/newlib')
led = json.load(open(f'{ROOT}/analysis/recovery-ledger.json'))
srcs = sorted({f['source'] for f in led['functions']})
# libm, newlib y libgcc se sustituyen por la plataforma (core/libc), no se convierten.
ZONE = (0x802e5574, 0x802f4ef0)
by_src = collections.defaultdict(list); names_by_src = collections.defaultdict(set)
for f in led['functions']:
    by_src[f['source']].append(int(f['address'], 16))
    names_by_src[f['source']].add(f.get('name') or f.get('symbol'))
platform = {s for s, ad in by_src.items() if all(ZONE[0] <= x < ZONE[1] for x in ad)}
skipped = [s for s in srcs if s.startswith(SKIP_PREFIX) or s in platform]
srcs = [s for s in srcs if s not in set(skipped)]
print('sustituidas por la plataforma', len(platform), 'omitidas en total', len(skipped))
inc = collections.defaultdict(list); flags = collections.defaultdict(list)
for mf in glob.glob(f'{ROOT}/config/GWMP8P/game-units/*.json'):
    try: m = json.load(open(mf))
    except Exception: continue
    if 'source' in m:
        inc[m['source']] = m.get('include_dirs', [])
if a.only: srcs = [s for s in srcs if re.search(a.only, s)]
if a.limit: srcs = srcs[::max(1, len(srcs) // a.limit)]
MAP = [(f'{ROOT}/source/matching/game', OUT), (f'{ROOT}/source/matching', f'{ROOT}/port/core/engine'), (f'{ROOT}/source/vendor', f'{ROOT}/port/core/vendor'), (f'{ROOT}/build', f'{ROOT}/port/core/build_src')]
ROOTS = [f'{ROOT}/source/matching', f'{ROOT}/source/vendor']
PATCH = {
 'k2b_a_801702b8.c': [(r'struct K2bHeader \{ unsigned char kind; unsigned char sub; unsigned char pad\[2\]; \}', 'struct K2bHeader { unsigned char pad[2]; unsigned char sub; unsigned char kind; }')],
 'autor_80022664.c': [(r'\(void \*\*\) M2C_FIELD\(arg0, Ptr32<Ptr32<void>> \*, 0x1C\)', '(s32) M2C_FIELD(arg0, s32 *, 0x1C)'), (r'w3d::G\(temp_r9_3\)', 'temp_r9_3')],
 'd24l_choice_icon_802a62bc.cpp': [(r'w3d_named_802b1510\(self->sub, \(\(Ptr32<ChNames>\)self\)->names\[self->index\]', 'w3d_named_802b1510(self->sub, (const char *)((Ptr32<ChNames>)self)->names[self->index]')],
 'd29c_chute_update_800db60c.cpp': [(r'\*\(struct W \{ int a, b, c; \} \*\)&self->pos = \*\(W \*\)&pos;', 'struct W { int a, b, c; }; *(W *)&self->pos = *(W *)&pos;')],
 'd30k_handler_notify_8021020c.cpp': [(r'while \(it != en\)', 'while (it != (Node *)en)')],
 'd28e_write_file_80204950.cpp': [(r'(template<class T> struct Array : Slots<T> \{)', r'\1 using Slots<T>::cap; using Slots<T>::end; using Slots<T>::begin; using Slots<T>::first; using Slots<T>::last;')],
 'd40e_renumber_classes_801e925c.cpp': [(r'(template<class T> struct Array : Slots<T> \{)', r'\1 using Slots<T>::cap; using Slots<T>::end; using Slots<T>::begin; using Slots<T>::first; using Slots<T>::last;')],
 'mx19oc_nested_vector_reserve_8034efd0.cpp': [(r'finish=uninitialized_copy_values\(', 'finish=uninitialized_copy_values<T>('), (r'(\s)uninitialized_copy_values\(w3d::R', r'\1uninitialized_copy_values<T>(w3d::R'), (r'destroy_range\(start,finish\)', 'destroy_range<T>(start,finish)'), (r'(struct NativeVector : VectorBase<T> \{)', r'\1 using VectorBase<T>::start; using VectorBase<T>::finish; using VectorBase<T>::end_of_storage;')],
 'cc39d_map_contains_8020e14c_v4.cpp': [(r'return \(Ptr32<cc39d_RbNode>\)header->parent;', 'return *(Ptr32<cc39d_RbNode> *)&header->parent;'), (r'return \(Ptr32<cc39d_RbNode>\)\((.*?)\);', r'return *(Ptr32<cc39d_RbNode> *)&(\1);')],
 'd28k_heap_allocate_80214344.cpp': [(r'unsigned int t = flags & ~16384UL;', 'unsigned int t; t = flags & ~16384UL;')],
 'd31a_target_list_build_800181e8.cpp': [(r'\+ w3d_auto_80015564\(i\) \+', '+ (const char *)w3d_auto_80015564(i) +')],
 'd31e_dump_object_801b25e8.cpp': [(r'<< w3d_auto_801ffea8\(cls\) <<', '<< (const char *)w3d_auto_801ffea8(cls) <<'), (r'<< item->prop->name <<', '<< (const char *)item->prop->name <<')],
 'd32h_hud_clock_layout_800a30bc.cpp': [(r'\) return r \{ (.*?) \}', r') { Vec r; \1 return r; }')],
 'd42k_button_build_802663dc_802663dc.cpp': [(r'Button::F\(Ref mgr, Arrow \*p,', 'Button::F(Ref mgr, Ptr32<Arrow> p,')],
 'd44l_icon_rows_rebuild_802aaf5c.cpp': [(r'\(\*\(Ptr32<Res> \*\)gp\)', '(*(Ptr32<Res> *)w3d::AG(gp))'), (r'\(\*\(Res \*\*\)gp\)', '(*(Ptr32<Res> *)w3d::AG(gp))')],
 'sol35e_stop_wormpot_802aa11c.cpp': [(r'\(\(unsigned\)&\(\((?:w3d::slot_t<T>|T) \*\)0\)->M\)', '__builtin_offsetof(T,M)')],
 'sol35e_text_mode_8025fa88.cpp': [(r'\(\(unsigned\)&\(\((?:w3d::slot_t<T>|T) \*\)0\)->M\)', '__builtin_offsetof(T,M)')],
 'h1_stlport_deque_init_map.cpp': [(r'W3dElem \*\*', r'Ptr32<W3dElem> *')],
 'h1_stlport_sort.cpp': [(r'\bT \*\* ?(?=\w)', 'Ptr32<T> *'), (r'\bT \*\*', 'Ptr32<T> *')],
 'h1_stlport_deque_realloc_map.cpp': [(r'W3dElem \*\*(\w+) =', r'Ptr32<W3dElem> *\1 ='), (r'w3d_copy\(Ptr32<T> \*first, Ptr32<T> \*last, Ptr32<T> \*result\)', 'w3d_copy(Ptr32<Ptr32<T>> first, Ptr32<Ptr32<T>> last, Ptr32<Ptr32<T>> result)'), (r'w3d_copy_backward\(Ptr32<T> \*first, Ptr32<T> \*last, Ptr32<T> \*result\)', 'w3d_copy_backward(Ptr32<Ptr32<T>> first, Ptr32<Ptr32<T>> last, Ptr32<Ptr32<T>> result)')],
 'f11c_dispatch_twice_801ac9a4.cpp': [(r'Ptr32<Ptr32<int \(Ptr32<F11c_Node400>, Ptr32<F11c_Header400>\)>> handlers\(\)\)\(F11c_Node400\*,F11c_Header400\*\)\{.*?\}\};', 'Ptr32<Ptr32<int (Ptr32<F11c_Node400>, Ptr32<F11c_Header400>)>> handlers() { return ((Ptr32<Ptr32<int (Ptr32<F11c_Node400>, Ptr32<F11c_Header400>)>> (*)(Ptr32<F11c_Peer400>))w3d::g2h(((w3d_u32 *)w3d::g2h(table.v))[10]))(this); }};')],
 '_iterator_base.h': [(r'(?s)(struct iterator_traits \{.*?\};)', r'''\1
// Los iteradores de vector son Ptr32 en memoria.
template <class _Tp> struct iterator_traits<Ptr32<_Tp> > {
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp value_type;
  typedef ptrdiff_t difference_type;
  typedef Ptr32<_Tp> pointer;
  typedef _Tp& reference;
};''', 1)],
 '_deque.h': [(r'return _M_map_size;', 'return this->_M_map_size;')],
 # C admite enumeradores dentro de un struct con ámbito de fichero; en C++ quedarían dentro de la clase.
 'inflate.c': [(r'(?s)(struct internal_state \{.*?)enum \{(.*?)\}(?:\s|/\*.*?\*/)*mode;', r'enum w3d_inflate_mode {\2};\n\1enum w3d_inflate_mode mode;', 1)],
 'infblock.c': [(r'(?s)(struct inflate_blocks_state \{.*?)enum \{(.*?)\}(?:\s|/\*.*?\*/)*mode;', r'enum w3d_block_mode {\2};\n\1enum w3d_block_mode mode;', 1)],
 'infblock.h': [(r'(?s)(struct inflate_blocks_state \{.*?)enum \{(.*?)\}(?:\s|/\*.*?\*/)*mode;', r'enum w3d_block_mode {\2};\n\1enum w3d_block_mode mode;', 1)],
 'infcodes.c': [(r'(?s)(struct inflate_codes_state \{.*?)enum \{(.*?)\}(?:\s|/\*.*?\*/)*mode;', r'enum w3d_codes_mode {\2};\n\1enum w3d_codes_mode mode;', 1)],
 'infutil.h': [(r'(?s)(struct inflate_blocks_state \{.*?)enum \{(.*?)\}(?:\s|/\*.*?\*/)*mode;', r'enum w3d_block_mode {\2};\n\1enum w3d_block_mode mode;', 1)],
 # GC: long == int.
 'd32f_parse_image_list_8028640c.cpp': [(r'\batol\s*\(', 'atoi(')],
 # Declaración variádica propia de memcpy: la de la libc del núcleo es la buena.
 'd30e_split_names_801d33b0.cpp': [(r'extern "C" Ptr32<void> memcpy\(\.\.\.\);', '#include <string.h>'), (r'extern "C" void \*memcpy\(\.\.\.\);', '#include <string.h>')],
 '*': [
  (r'typedef (Ptr32<[^;\n]*>) (\w+)\s+OF\(\(.*?\)\);', r'typedef \1 \2;'),
  (r'\bOF\(\((.*?)\)\)(?=\s*[;{\n,)])', lambda m: '(' + re.sub(r'((?:const\s+)?\w+)\s*\*\s*(?=\w+\s*(?:,|$))', r'Ptr32<\1> ', m.group(1)) + ')'),
  (r'::\s*(?:_STLP_TEMPLATE\s+)?rebind\s*<', '::template rebind<'),
  (r'##header##', 'header'),
  (r'\(\s*(?:unsigned(?:\s+int)?|int|size_t|u32)\s*\)\s*&\s*\(\s*\(\s*(?:Ptr32<\s*)?(\w+)\s*(?:\*|>)\s*\)\s*0\s*\)\s*->\s*([\w.\[\]]+)', r'__builtin_offsetof(\1,\2)'),
  (r'operator\s+new(\[\])?\s*\(\s*unsigned(\s+int)?\b', r'operator new\1(__SIZE_TYPE__'),
  (r'operator\s+new(\[\])?\s*\(\s*size_t\b', r'operator new\1(__SIZE_TYPE__'),
  (r'#define M2C_FIELD\(expr, type_ptr, offset\)[^\n]*', '#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)(w3d::bytes(expr) + (offset)))'),
]}
def dirs_for(s):
    r = [os.path.join(ROOT, d) for d in inc.get(s, [])] + [f'{ROOT}/source/matching', os.path.dirname(os.path.join(ROOT, s))]
    return r
def do_lift(s):
    p = os.path.join(ROOT, s)
    lang = 'c++' if s.endswith(('.cpp', '.cc')) else 'c'
    fl = [f'-I{d}' for d in dirs_for(s)] + [f'-I{ROOT}/tools/reference-headers']
    try:
        l, w = lift_file(p, lang, fl, ROOTS + [os.path.dirname(p)], MAP, PATCH, ledger_names=names_by_src.get(s))
        return s, 'ok', w, dict(l.stats), l.problems[:6], l.pmf_fields
    except Exception as ex:
        return s, 'lift_error', [], {}, [repr(ex)[:300]], []
def out_of(s):
    for src, o in MAP:
        if os.path.join(ROOT, s).startswith(src + os.sep):
            d = os.path.join(o, os.path.relpath(os.path.join(ROOT, s), src))
            return d[:-2] + '.cpp' if d.endswith('.c') else d
    return None
CC = [f'{ROOT}/port/tools/lift/cc_core.sh']
def do_cc(s):
    d = out_of(s)
    if not d or not os.path.exists(d): return s, -1, ['no generado'], 0
    obj = f'{TMP}/objs/' + re.sub(r'[^\w]', '_', s) + '.o'
    os.makedirs(f'{TMP}/objs', exist_ok=True)
    extra = []
    if a.ir:
        os.makedirs(f'{TMP}/ll', exist_ok=True)
        obj = f'{TMP}/ll/' + re.sub(r'[^\w]', '_', s) + '.ll'; extra = ['-S', '-emit-llvm', '-g0', '-O0', '-Xclang', '-disable-O0-optnone']
    idirs = []
    for x in dirs_for(s):
        for src, o in MAP:
            if os.path.realpath(x) == os.path.realpath(src) or os.path.realpath(x).startswith(os.path.realpath(src) + os.sep):
                idirs += ['-I', os.path.join(o, os.path.relpath(os.path.realpath(x), os.path.realpath(src)))]
    p = subprocess.run(CC + [a.target, obj, d, '-ferror-limit=0'] + extra + idirs + [f'-I{ROOT}/port/core/runtime', f'-I{ROOT}/port/core', f'-I{ROOT}/port/core/lua/include'], capture_output=True, text=True, errors='replace', timeout=240)
    errs = re.findall(r'^[^\n]*?error: ([^\n]*)$', p.stderr, flags=re.M)
    return s, p.returncode, errs, os.path.getsize(obj) if p.returncode == 0 and os.path.exists(obj) else 0
tot = collections.Counter(); prob = []; pmf = []
if not a.no_lift:
    with cf.ThreadPoolExecutor(a.jobs) as ex:
        for s, st, w, stats, pr, pf in ex.map(do_lift, srcs):
            tot['lift_' + st] += 1
            for k, v in stats.items(): tot[k] += v
            prob += [f'{s}: {x}' for x in pr]
            pmf += [f'{s}: {x}' for x in pf]
    print({k: v for k, v in tot.items()})
    print('problemas', len(prob)); print('\n'.join(p[:200] for p in prob[:10]))
# Inversiones de bytes del lector de archivos: en little-endian sobran.
import le_fix
for u_ in le_fix.LE_UNITS:
    for s_ in srcs:
        if os.path.basename(s_).rsplit('.', 1)[0] == u_:
            o_ = out_of(s_)
            if o_ and os.path.exists(o_) and not a.no_lift: le_fix.apply(o_)
# Punteros a método: forma de GCC 2.95 en vez de la de Itanium.
import word_view_fix
n_ = 0
for r_, _, fs_ in os.walk(f'{ROOT}/port/core'):
    if a.no_lift: break
    for f_ in fs_:
        if f_.endswith(('.cpp', '.c', '.h')): n_ += word_view_fix.apply(os.path.join(r_, f_))
print('vistas de media palabra corregidas', n_)
# Correcciones sueltas de la auditoría de bytes (port/docs-data/audit-bytes.json) y propias. Las de core/open se pierden si se regenera con ppc2cpp.
if not a.no_lift:
    for d_ in sorted(glob.glob(f'{ROOT}/port/tools/lift/audit_patches/*.diff')):
        r_ = subprocess.run(['patch', '-p1', '-N', '-s', '-i', d_], cwd=ROOT, capture_output=True, text=True)
        if r_.returncode: print('parche sin aplicar', os.path.basename(d_), r_.stdout[-200:])
import pmf_fix
if not a.no_lift:
    n_ = 0
    for s_ in srcs:
        o_ = out_of(s_)
        if o_ and os.path.exists(o_): n_ += bool(pmf_fix.apply(o_))
    print('punteros a método en', n_, 'unidades')
# Correcciones a mano sobre lo convertido: port/core/fixes/<ruta dentro de port/core>.
FIX = f'{ROOT}/port/core/fixes'
for r_, _, fs_ in os.walk(FIX) if not a.no_lift else ():  # con --no-lift no se toca el árbol
    for x_ in fs_:
        rel = os.path.relpath(os.path.join(r_, x_), FIX)
        dst = f'{ROOT}/port/core/{rel}'
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copyfile(os.path.join(r_, x_), dst)
E0 = collections.Counter(); F0 = collections.Counter(); ok = 0; bad = []; detail = {}
norm = lambda m: re.sub(r"'[^']*'", "'_'", m)[:100]
with cf.ThreadPoolExecutor(a.jobs) as ex:
    for s, rc, errs, sz in ex.map(do_cc, srcs):
        if rc == 0: ok += 1
        else:
            bad.append((s, len(errs))); detail[s] = errs[:12]
            for e in set(map(norm, errs)): F0[e] += 1
            for e in errs: E0[norm(e)] += 1
print('compilan', ok, 'de', len(srcs), 'fallan', len(bad))
print('--- errores por nº de archivos'); [print(' ', n, e) for e, n in F0.most_common(35)]
if a.ir: sys.exit(0)
fin = dict(target=a.target, total=len(srcs), ok=ok, failing=len(bad), skipped=len(skipped), errors_by_file=F0.most_common(120), errors_by_count=E0.most_common(60), bad_sample=sorted(bad, key=lambda x: x[1])[:80], lift_stats=tot, problems=prob[:200], member_pointer_fields=sorted(set(pmf)))
if a.target == ap.get_default('target'): json.dump(fin, open(f'{ROOT}/port/docs-data/lift-census.json', 'w'), indent=1)  # el censo es del destino principal
if a.only and os.path.exists(f'{TMP}/lift-errors.json'):
    # Una pasada parcial solo actualiza las fuentes que ha compilado.
    prev = json.load(open(f'{TMP}/lift-errors.json'))
    for s_ in srcs: prev.pop(s_, None)
    prev.update(detail); detail = prev
json.dump(detail, open(f'{TMP}/lift-errors.json', 'w'), indent=0)
