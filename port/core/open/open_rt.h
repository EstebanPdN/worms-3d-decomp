// Ayudas de las funciones de core/open: traducidas de los bytes PPC, sin fuente admitida y NO verificadas.
// Registros locales de 32 bits, memoria en la ventana (w3d_ptr.h), little-endian. Ver port/tests/open/ppc2cpp.py.
#ifndef W3D_OPEN_RT_H
#define W3D_OPEN_RT_H
#include "w3d_ptr.h"
#include <stdint.h>
#include <string.h>

typedef uint64_t w3d_u64;
typedef w3d_uptr w3d_oarg;  // Argumento genérico: registro entero del anfitrión.
typedef int32_t w3d_s32;
typedef int64_t w3d_s64;
using namespace w3d;

extern "C" {
extern char w3d_dol_image[], w3d_low_image[];
void w3d_open_break(w3d_u32 addr);                       // Palabra 0x00000001 del original: trampa al depurador.
w3d_u32 w3d_open_fn(w3d_u32 addr);                       // Dirección original de función -> puntero guardado.
// Destino oculto de arm64 (x8) frente a PPC (r3). Los flotantes pasan intactos por v0-v7.
void w3d_open_sret(void *fn, w3d_oarg dst, w3d_oarg a0, w3d_oarg a1, w3d_oarg a2, w3d_oarg a3, w3d_oarg a4, w3d_oarg a5,
                   float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8);
}

#define W3D_OPEN_INL static inline __attribute__((always_inline))

// Datos fijos: mismo desplazamiento que en el DOL dentro de un bloque contiguo.
W3D_OPEN_INL w3d_u32 D(w3d_u32 k) { return h2g(w3d_dol_image) + (k - 0x8035f3e0u); }
W3D_OPEN_INL w3d_u32 LOW(w3d_u32 k) { return h2g(w3d_low_image) + (k - 0x80000000u); }
#define FN(k) w3d_open_fn(k)
W3D_OPEN_INL w3d_oarg W(w3d_u32 v) { return (w3d_oarg)g2h(v); }  // Con los bits altos: vale para enteros y para punteros reales.

// Memoria. Un puntero nulo más un desplazamiento pequeño debe fallar en voz alta, sin leer la cabecera del ejecutable que
// hay en la base de la ventana. Por eso no se usa g2h: clang borraría su comprobación de nulo al ver el acceso.
#if W3D_POINTER_64
W3D_OPEN_INL void *MA(w3d_u32 a) { return (void *)(a >= 0x1000u ? (kWindow | a) : (w3d_uptr)a + 8); }
#else
W3D_OPEN_INL void *MA(w3d_u32 a) { return (void *)(w3d_uptr)a; }
#endif
W3D_OPEN_INL w3d_u32 L32(w3d_u32 a) { w3d_u32 v; memcpy(&v, MA(a), 4); return v; }
W3D_OPEN_INL w3d_u32 L16(w3d_u32 a) { uint16_t v; memcpy(&v, MA(a), 2); return v; }
W3D_OPEN_INL w3d_u32 LS16(w3d_u32 a) { int16_t v; memcpy(&v, MA(a), 2); return (w3d_u32)(w3d_s32)v; }
W3D_OPEN_INL w3d_u32 L8(w3d_u32 a) { return *(uint8_t *)MA(a); }
W3D_OPEN_INL void S32(w3d_u32 a, w3d_u32 v) { memcpy(MA(a), &v, 4); }
W3D_OPEN_INL void S16(w3d_u32 a, w3d_u32 v) { uint16_t t = (uint16_t)v; memcpy(MA(a), &t, 2); }
W3D_OPEN_INL void S8(w3d_u32 a, w3d_u32 v) { *(uint8_t *)MA(a) = (uint8_t)v; }
W3D_OPEN_INL double LF(w3d_u32 a) { float v; memcpy(&v, MA(a), 4); return v; }
W3D_OPEN_INL void SF(w3d_u32 a, double v) { float t = (float)v; memcpy(MA(a), &t, 4); }
W3D_OPEN_INL double LD(w3d_u32 a) { double v; memcpy(&v, MA(a), 8); return v; }
W3D_OPEN_INL void SD(w3d_u32 a, double v) { memcpy(MA(a), &v, 8); }
// Doble en pila que además se toca por palabras: palabra alta primero, como lo ve GCC 2.95 en PPC.
W3D_OPEN_INL double LDS(w3d_u32 a) { w3d_u64 b = ((w3d_u64)L32(a) << 32) | L32(a + 4); double v; memcpy(&v, &b, 8); return v; }
W3D_OPEN_INL void SDS(w3d_u32 a, double v) { w3d_u64 b; memcpy(&b, &v, 8); S32(a, (w3d_u32)(b >> 32)); S32(a + 4, (w3d_u32)b); }
W3D_OPEN_INL void DCBZ(w3d_u32 a) { memset(MA(a & ~31u), 0, 32); }

// Comparaciones: máscara de campo CR (LT=8, GT=4, EQ=2, SO/desordenado=1).
W3D_OPEN_INL w3d_u32 CMPS(w3d_u32 a, w3d_s32 b) { w3d_s32 x = (w3d_s32)a; return x < b ? 8 : x > b ? 4 : 2; }
W3D_OPEN_INL w3d_u32 CMPU(w3d_u32 a, w3d_u32 b) { return a < b ? 8 : a > b ? 4 : 2; }
W3D_OPEN_INL w3d_u32 CMPF(double a, double b) { return a < b ? 8 : a > b ? 4 : a == b ? 2 : 1; }

// Enteros con la semántica de PPC donde C++ no la da.
W3D_OPEN_INL w3d_u32 ROTL(w3d_u32 v, unsigned n) { n &= 31; return n ? (v << n) | (v >> (32 - n)) : v; }
W3D_OPEN_INL w3d_u32 SLW(w3d_u32 v, w3d_u32 n) { return (n & 32) ? 0 : v << (n & 31); }
W3D_OPEN_INL w3d_u32 SRW(w3d_u32 v, w3d_u32 n) { return (n & 32) ? 0 : v >> (n & 31); }
W3D_OPEN_INL w3d_u32 SRAW(w3d_u32 v, w3d_u32 n) { return (n & 32) ? (w3d_u32)((w3d_s32)v >> 31) : (w3d_u32)((w3d_s32)v >> (n & 31)); }
W3D_OPEN_INL w3d_u32 SRAWCA(w3d_u32 v, w3d_u32 n) {
    if (!(v >> 31)) return 0;
    if (n & 32) return 1;
    n &= 31;
    return n && (v << (32 - n)) != 0;
}
// La división por cero y INT_MIN/-1 no atrapan en PPC; el resultado queda indefinido. Aquí, 0.
W3D_OPEN_INL w3d_u32 DIVS(w3d_u32 a, w3d_u32 b) { return (b == 0 || (a == 0x80000000u && b == 0xffffffffu)) ? 0 : (w3d_u32)((w3d_s32)a / (w3d_s32)b); }
W3D_OPEN_INL w3d_u32 DIVU(w3d_u32 a, w3d_u32 b) { return b ? a / b : 0; }

// Flotante -> entero. PPC satura y NaN da 0x80000000; arm64 da 0 con NaN.
W3D_OPEN_INL double fpr_bits(w3d_u32 v) { w3d_u64 b = 0xfff8000000000000ull | v; double d; memcpy(&d, &b, 8); return d; }
W3D_OPEN_INL double FCTIWZ(double x) {
    w3d_s32 v;
    if (x != x) v = (w3d_s32)0x80000000;
    else if (x >= 2147483648.0) v = 0x7fffffff;
    else if (x <= -2147483649.0) v = (w3d_s32)0x80000000;
    else v = (w3d_s32)x;
    return fpr_bits((w3d_u32)v);
}
W3D_OPEN_INL double FCTIW(double x) { return x != x ? fpr_bits(0x80000000u) : FCTIWZ(__builtin_rint(x)); }

// psq con GQR2-5 (u8, u16, s8, s16; escala 0): los fija 0x80167118. Conversión a entero con saturación y truncamiento.
template <class T> W3D_OPEN_INL T psq_clamp(double v, double lo, double hi) { float f = (float)v; return f != f ? (T)0 : f <= lo ? (T)lo : f >= hi ? (T)hi : (T)f; }
W3D_OPEN_INL double PSQL_U8(w3d_u32 a) { return (float)L8(a); }
W3D_OPEN_INL double PSQL_U16(w3d_u32 a) { return (float)L16(a); }
W3D_OPEN_INL double PSQL_S8(w3d_u32 a) { return (float)(int8_t)L8(a); }
W3D_OPEN_INL double PSQL_S16(w3d_u32 a) { return (float)(w3d_s32)LS16(a); }
W3D_OPEN_INL void PSQS_U8(w3d_u32 a, double v) { S8(a, psq_clamp<uint8_t>(v, 0, 255)); }
W3D_OPEN_INL void PSQS_U16(w3d_u32 a, double v) { S16(a, psq_clamp<uint16_t>(v, 0, 65535)); }
W3D_OPEN_INL void PSQS_S8(w3d_u32 a, double v) { S8(a, (w3d_u32)psq_clamp<int8_t>(v, -128, 127)); }
W3D_OPEN_INL void PSQS_S16(w3d_u32 a, double v) { S16(a, (w3d_u32)psq_clamp<int16_t>(v, -32768, 32767)); }

// Llamada con la forma genérica: enteros en x0-x7 con los bits altos puestos y flotantes en s0-s7.
// En arm64 los argumentos de más no molestan, y los dos bancos son independientes como en PPC.
typedef w3d_u32 (*w3d_open_gi)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float, float, float, float, float, float, float, float);
typedef float (*w3d_open_gf)(w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, w3d_oarg, float, float, float, float, float, float, float, float);
template <class F> W3D_OPEN_INL w3d_u32 CU(F fn, w3d_u32 a, w3d_u32 b, w3d_u32 c, w3d_u32 d, w3d_u32 e, w3d_u32 f, w3d_u32 g, w3d_u32 h,
                                         double s, double t, double u, double v, double w, double x, double y, double z) {
    return ((w3d_open_gi)fn)(W(a), W(b), W(c), W(d), W(e), W(f), W(g), W(h), (float)s, (float)t, (float)u, (float)v, (float)w, (float)x, (float)y, (float)z);
}
template <class F> W3D_OPEN_INL double CUF(F fn, w3d_u32 a, w3d_u32 b, w3d_u32 c, w3d_u32 d, w3d_u32 e, w3d_u32 f, w3d_u32 g, w3d_u32 h,
                                         double s, double t, double u, double v, double w, double x, double y, double z) {
    return ((w3d_open_gf)fn)(W(a), W(b), W(c), W(d), W(e), W(f), W(g), W(h), (float)s, (float)t, (float)u, (float)v, (float)w, (float)x, (float)y, (float)z);
}

// Agregados que clang devuelve por valor en registros y GCC 2.95 por puntero oculto.
struct w3d_open_pair { w3d_u64 a, b; };
struct w3d_open_vec3 { float x, y, z; };
W3D_OPEN_INL void w3d_open_store(w3d_u32 dst, const w3d_open_vec3 &v) { memcpy(g2h(dst), &v, 12); }
W3D_OPEN_INL void w3d_open_store(w3d_u32 dst, const w3d_open_pair &v) { memcpy(g2h(dst), &v, 16); }
W3D_OPEN_INL w3d_open_pair w3d_open_pair_at(w3d_u32 p) { w3d_open_pair v; memcpy(&v, g2h(p), 16); return v; }

#include "open_decls.h"
#endif
