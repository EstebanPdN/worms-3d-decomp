// Soporte de las funciones de core/open. Lo que hay aquí no viene del original: es lo mínimo para que enlacen y avisen.
#include "open_rt.h"
#include <stdio.h>
#include <stdlib.h>

extern "C" {
struct W3dFnEntry { uint32_t addr, pad; void *fn; };
extern const W3dFnEntry w3d_fn_table[];
extern const uint32_t w3d_fn_table_count;
int w3d_sscanf(w3d_u32 s, w3d_u32 f, ...);

// 0x00000001 precede a métodos virtuales triviales y el juego los llama en su arranque normal; se sigue con el cuerpo. Antes se creía que era
// ramas "no debería pasar" y en métodos virtuales sin implementar. Aquí se avisa una vez por dirección y se sigue.
void w3d_open_break(w3d_u32 addr) { (void)addr; }

// Tabla dirección -> función que genera link_all.py, con la vista de 32 bits de cada función.
w3d_u32 w3d_open_fn(w3d_u32 addr) {
    uint32_t lo = 0, hi = w3d_fn_table_count;
    while (lo < hi) {
        uint32_t m = (lo + hi) / 2;
        if (w3d_fn_table[m].addr < addr) lo = m + 1; else hi = m;
    }
    if (lo < w3d_fn_table_count && w3d_fn_table[lo].addr == addr) return h2g(w3d_fn_table[lo].fn);
    fflush(stdout);
    fprintf(stderr, "[open] función 0x%08x sin entrada en la tabla\n", addr);
    abort();
}

// exit de newlib: ninguna unidad admitida la referencia, así que el enlace no crea su stub.
__attribute__((weak)) void A802ed984(int code) { fflush(stdout); exit(code); }

// Fuentes admitidas que aún no compilan a arm64 y que solo llaman funciones de core/open.
// Débiles: si la unidad llega a compilar, hay que quitarlas (ver port/docs-data/open-functions.json).
void w3d_report_missing(uint32_t addr, void *lr);
#define OPEN_MISSING(a) __attribute__((weak)) void A##a(void) { w3d_report_missing(0x##a, __builtin_return_address(0)); }
}

// sscanf: reenvío directo, mismos registros y misma pila de variádicos que w3d_sscanf.
#if defined(__aarch64__)
__asm__(".text\n.p2align 2\n.globl _A802ec334\n.weak_definition _A802ec334\n_A802ec334:\n  b _w3d_sscanf\n");
#else
__asm__(".text\n.p2align 2\n.weak A802ec334\nA802ec334:\n  b w3d_sscanf\n");
#endif

// w3d_open_sret: x0=función, x1=destino oculto, x2-x7=argumentos enteros; v0-v7 sin tocar.
#if defined(__aarch64__)
__asm__(".text\n.p2align 2\n.globl _w3d_open_sret\n_w3d_open_sret:\n"
        "  mov x9, x0\n  mov x8, x1\n  mov x0, x2\n  mov x1, x3\n  mov x2, x4\n  mov x3, x5\n  mov x4, x6\n  mov x5, x7\n  br x9\n");
#else
// En ARM el destino oculto ya es el primer entero: se llama con los argumentos tal cual.
extern "C" void w3d_open_sret(void *fn, w3d_oarg dst, w3d_oarg a0, w3d_oarg a1, w3d_oarg a2, w3d_oarg a3, w3d_oarg a4, w3d_oarg a5,
                              float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8) {
    ((void (*)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float, float, float, float, float, float, float, float))fn)(dst, a0, a1, a2, a3, a4, a5, f1, f2, f3, f4, f5, f6, f7, f8);
}
#endif
