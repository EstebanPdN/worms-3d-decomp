#!/usr/bin/env python3
"""Prueba diferencial del traductor PPC -> C++.

Toma funciones hoja ya admitidas (coinciden byte a byte con el DOL y tienen fuente propia), las traduce también desde
sus bytes con ppc2cpp.py, y compara la versión traducida contra la compilada desde la fuente sobre entradas aleatorias.
Una diferencia señala un fallo del traductor, de la conversión de la unidad o un dato dependiente del orden de bytes.

Genera un .cpp que sustituye al main del juego dentro de un binario privado: el DOL ya está cargado y no se simula nada.
Uso: diff_test.py <sigs.json> <salida.cpp> [máximo]
"""
import json, os, random, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.argv, args = sys.argv[:1], sys.argv[1:]
import ppc2cpp as P

sigs_path, out = args[0], args[1]
limit = int(args[2]) if len(args) > 2 else 2000
data = json.load(open(sigs_path)); sigs = P.Sigs(data)
errors = json.load(open('/tmp/w3dp/lift-errors.json'))
led = json.load(open(f'{P.ROOT}/analysis/recovery-ledger.json'))['functions']
starts = P.load_starts()
cands = []
skipcat = {}
for f in led:
    a = int(f['address'], 16)
    if not (0x80003100 <= a < 0x802e34a4 or 0x80341348 <= a < 0x8035f3e0): continue  # Código del juego.
    if f['source'] in errors or f['bytes'] > 3000 or a not in sigs.defs: continue
    r, ps = sigs.defs[a]
    if r not in ('I', 'L', 'P', 'F', 'V') or any(x not in ('I', 'L', 'P', 'F') for x in ps) or len(ps) > 8 or not ps: continue
    fn = P.Fn(a, f.get('name') or '', 'prueba')
    try:
        P.build(fn, starts); P.constprop(fn); P.analyze_frame(fn)
    except Exception:
        continue
    bad = False
    for x, i in fn.ins.items():
        if i.op == 'b' and i.lk or i.op in ('bclr', 'bcctr') and i.lk or (i.op == 'b' and i.target not in fn.ins) or i.op == 'bc' and i.target not in fn.ins or x in fn.fallin:
            bad = True; break
        if i.op in ('word',) or x in fn.trapafter: bad = True; break
        if i.op in ('mem', 'memx') and not i.load:
            e = P.ea_info(i, fn.state[x])
            if e and e[0] == 'c': bad = True; break  # Escribe en un global: con estado.
    if bad or fn.warn: continue
    fn.ret = 'F' if r == 'F' else 'I'
    cands.append((a, fn, r, ps))
random.Random(1).shuffle(cands)
cands = cands[:limit]
lifted = {a: fn for a, fn, _, _ in cands}
for it in range(3):
    for a, fn in lifted.items():
        lv = P.liveness(fn, sigs, {})
        fn.pi = max(max([P.INTS.index(x) + 1 for x in lv if x in P.INTS], default=0), fn.pi); fn.pf = max(max([P.FLTS.index(x) + 1 for x in lv if x in P.FLTS], default=0), fn.pf)
        P.liveness(fn, sigs, {}, precise=True)
bodies = {}
for a, fn, r, ps in cands:
    e = P.Emit(fn, sigs, {}, starts)
    try: bodies[a] = e.text()
    except P.W: pass
rows = []
with open(out, 'w') as f:
    f.write('#include "open_rt.h"\n#include <stdio.h>\n#include <stdlib.h>\n#include <unistd.h>\n#include <signal.h>\n#include <sys/wait.h>\n#include <math.h>\n')
    f.write('namespace w3d { void *arena_alloc(unsigned long n); }\nextern "C" {\n')
    for a, fn, r, ps in cands:
        if a not in bodies: continue
        txt = '\n'.join(bodies[a]).replace(' A%08x(' % a, ' T%08x(' % a)
        f.write(txt + '\n')
    f.write('}\n')
    f.write('typedef w3d_u64 (*GI)(w3d_u64,w3d_u64,w3d_u64,w3d_u64,w3d_u64,w3d_u64,w3d_u64,w3d_u64,float,float,float,float,float,float,float,float);\n')
    f.write('typedef float (*GF)(w3d_u64,w3d_u64,w3d_u64,w3d_u64,w3d_u64,w3d_u64,w3d_u64,w3d_u64,float,float,float,float,float,float,float,float);\n')
    f.write('struct Row { w3d_u32 addr; void *a, *t; char ret; const char *ps; };\nextern "C" {\n')
    for a, fn, r, ps in cands:
        if a in bodies: f.write('void A%08x();\n' % a)
    f.write('}\nstatic const Row rows[] = {\n')
    for a, fn, r, ps in cands:
        if a in bodies: f.write('{0x%08xu, (void*)A%08x, (void*)T%08x, \'%s\', "%s"},\n' % (a, a, a, r, ''.join(ps)))
    f.write('};\n')
    f.write(r'''
static unsigned long long rs = 88172645463325252ull;
static unsigned rnd() { rs ^= rs << 13; rs ^= rs >> 7; rs ^= rs << 17; return (unsigned)(rs >> 16); }
static float rfl() { switch (rnd() % 8) { case 0: return 0; case 1: return 1; case 2: return -1; case 3: return 0.5f; case 4: return (float)(rnd() % 2001) - 1000.f; default: return ((float)(rnd() % 200001) - 100000.f) / 1000.f; } }
static w3d_u32 rint_() { switch (rnd() % 6) { case 0: return 0; case 1: return 1; case 2: return (w3d_u32)-1; case 3: return rnd() % 16; case 4: return rnd() % 256; default: return rnd(); } }
static const int BUF = 2048, NB = 8;
static char *orig[NB], *b1[NB], *b2[NB];
static void fill(char *p) { for (int i = 0; i < BUF; i += 4) { unsigned k = rnd() % 4; w3d_u32 v; if (k == 0) { float f = rfl(); memcpy(&v, &f, 4); } else if (k == 1) v = rnd() % 8; else if (k == 2) v = 0; else v = rnd() % 256; memcpy(p + i, &v, 4); } }
static volatile int stage;
static int run_one(const Row &r, int fd) {
    w3d_u64 ia[8], ib[8]; float fa[8]; memset(ia, 0, sizeof ia); memset(ib, 0, sizeof ib); memset(fa, 0, sizeof fa);
    for (int it = 0; it < 200; it++) {
        int ni = 0, nf = 0, nb = 0;
        for (int b = 0; b < NB; b++) { fill(orig[b]); memcpy(b1[b], orig[b], BUF); }
        for (const char *s = r.ps; *s; s++) {
            if (*s == 'F') { if (nf < 8) fa[nf++] = rfl(); continue; }
            if (*s == 'I') { w3d_u32 v = rint_(); ia[ni] = W(v); ib[ni] = W(v); ni++; continue; }
            ia[ni] = (w3d_u64)(b1[nb] + 256); ib[ni] = ia[ni]; ni++; nb = (nb + 1) % NB;  // L y P: punteros.
        }
        w3d_u32 ra = 0, rb = 0; unsigned char st = 'A'; write(fd, &st, 1);
        if (r.ret == 'F') { float x = ((GF)r.a)(ia[0],ia[1],ia[2],ia[3],ia[4],ia[5],ia[6],ia[7],fa[0],fa[1],fa[2],fa[3],fa[4],fa[5],fa[6],fa[7]); memcpy(&ra, &x, 4); }
        else ra = (w3d_u32)((GI)r.a)(ia[0],ia[1],ia[2],ia[3],ia[4],ia[5],ia[6],ia[7],fa[0],fa[1],fa[2],fa[3],fa[4],fa[5],fa[6],fa[7]);
        // Mismas direcciones para las dos versiones: se guarda el resultado y se restaura la entrada.
        for (int b = 0; b < NB; b++) { memcpy(b2[b], b1[b], BUF); memcpy(b1[b], orig[b], BUF); }
        st = 'T'; write(fd, &st, 1);
        if (r.ret == 'F') { float x = ((GF)r.t)(ib[0],ib[1],ib[2],ib[3],ib[4],ib[5],ib[6],ib[7],fa[0],fa[1],fa[2],fa[3],fa[4],fa[5],fa[6],fa[7]); memcpy(&rb, &x, 4); }
        else rb = (w3d_u32)((GI)r.t)(ib[0],ib[1],ib[2],ib[3],ib[4],ib[5],ib[6],ib[7],fa[0],fa[1],fa[2],fa[3],fa[4],fa[5],fa[6],fa[7]);
        bool diff = false;
        if (r.ret != 'V') {
            if (r.ret == 'F') { float x, y; memcpy(&x, &ra, 4); memcpy(&y, &rb, 4); diff = !(ra == rb || (x != x && y != y)); }
            else diff = ra != rb;
        }
        if (diff) { printf("DIF 0x%08x ret %s it=%d a=%08x t=%08x\n", r.addr, r.ps, it, ra, rb); fflush(stdout); return 1; }
        for (int b = 0; b < NB; b++) if (memcmp(b1[b], b2[b], BUF)) {
            int o = 0; while (b1[b][o] == b2[b][o]) o++;
            printf("DIF 0x%08x mem %s it=%d buf=%d off=%d a=%02x t=%02x\n", r.addr, r.ps, it, b, o - 256, (unsigned char)b2[b][o], (unsigned char)b1[b][o]); fflush(stdout); return 1;
        }
    }
    return 0;
}
extern "C" int A8015ad40(int, w3d_u32) {
    for (int b = 0; b < NB; b++) { orig[b] = (char *)arena_alloc(BUF); b1[b] = (char *)arena_alloc(BUF); b2[b] = (char *)arena_alloc(BUF); }
    int n = sizeof rows / sizeof rows[0], same = 0, dif = 0, crA = 0, crT = 0, hang = 0;
    for (int i = 0; i < n; i++) {
        int pf[2]; pipe(pf); fflush(stdout);
        pid_t p = fork();
        if (!p) { close(pf[0]); alarm(3); signal(SIGABRT, SIG_DFL); _exit(run_one(rows[i], pf[1])); }
        close(pf[1]); unsigned char c = 0, last = 0; while (read(pf[0], &c, 1) == 1) last = c;
        close(pf[0]); int st; waitpid(p, &st, 0);
        if (WIFEXITED(st)) { if (WEXITSTATUS(st) == 0) same++; else dif++; }
        else if (WTERMSIG(st) == SIGALRM) { hang++; printf("HANG 0x%08x %c\n", rows[i].addr, last); }
        else if (last == 'T') { crT++; printf("CRASH-T 0x%08x %s sig=%d\n", rows[i].addr, rows[i].ps, WTERMSIG(st)); }
        else crA++;
    }
    printf("RESUMEN funciones=%d iguales=%d diferentes=%d fallo_solo_traducida=%d fallo_fuente=%d colgadas=%d\n", n, same, dif, crT, crA, hang);
    fflush(stdout);
    _exit(0);
}
''')
print('candidatas', len(cands), 'emitidas', len(bodies))
