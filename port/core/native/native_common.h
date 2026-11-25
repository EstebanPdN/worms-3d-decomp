// Ayudas de las funciones del juego reescritas a mano en core/native.
// Las estructuras guardan la disposición de GameCube: enteros y flotantes en orden del anfitrión, punteros en 4 B (Ptr32).
// Un objeto con métodos virtuales lleva la tabla en su primera palabra; cada entrada es un puntero guardado a la función.
//
// Argumentos: en PPC, r4-r10 y f1-f8 que una función no toca siguen vivos en la que llama, y muchos reenvíos del original
// no dicen cuántos pasan (0x802185c8 lleva un cuarto argumento que su declaración no menciona). En arm64 un registro no declarado
// puede usarse de temporal, así que un reenvío declara y pasa todos: REGS_x son los parámetros desde el registro x (a = x0)
// y PASS_x los mismos con bits altos, porque el destino puede recibirlos por T* o T&. Mantienen la posición, como en PPC.
#ifndef W3D_NATIVE_COMMON_H
#define W3D_NATIVE_COMMON_H
#include "w3d_ptr.h"
#include <stdint.h>
#include <string.h>
using namespace w3d;

// Entero o puntero guardado que pasa a otra función sin saber cuál espera: con los bits altos vale para las dos cosas.
inline void *arg(w3d_u32 value) { return g2h(value); }
#define FLOAT_REGS float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8
#define PASS_FLOATS s1, s2, s3, s4, s5, s6, s7, s8
#define REGS_H w3d_u32 h, FLOAT_REGS
#define REGS_G w3d_u32 g, REGS_H
#define REGS_F w3d_u32 f, REGS_G
#define REGS_E w3d_u32 e, REGS_F
#define REGS_D w3d_u32 d, REGS_E
#define REGS_C w3d_u32 c, REGS_D
#define REGS_B w3d_u32 b, REGS_C
#define REGS_A w3d_u32 a, REGS_B
#define PASS_H arg(h), PASS_FLOATS
#define PASS_G arg(g), PASS_H
#define PASS_F arg(f), PASS_G
#define PASS_E arg(e), PASS_F
#define PASS_D arg(d), PASS_E
#define PASS_C arg(c), PASS_D
#define PASS_B arg(b), PASS_C
#define PASS_A arg(a), PASS_B
typedef w3d_u32 (*AllRegs)(void *, void *, void *, void *, void *, void *, void *, void *, float, float, float, float, float, float, float, float);
template <class T> inline T *at(w3d_u32 guest) { return (T *)g2h(guest); }
template <class R = w3d_u32, class... A> inline R call_in_table(const void *object, w3d_u32 table, unsigned offset, A... args) {
    const w3d_u32 entry = *at<const w3d_u32>(table + offset);
    return ((R (*)(const void *, A...))g2h(entry))(object, args...);
}
// Método virtual con su desplazamiento en la tabla.
template <class R = w3d_u32, class... A> inline R call_virtual(const void *object, unsigned offset, A... args) {
    return call_in_table<R>(object, *(const w3d_u32 *)object, offset, args...);
}
// Conversión con la semántica de fctiwz: satura y NaN da INT_MIN. arm64 da 0 con NaN.
inline int32_t ppc_ftoi(double x) {
    if (x != x || x <= -2147483649.0) return INT32_MIN;
    if (x >= 2147483648.0) return INT32_MAX;
    return (int32_t)x;
}
// fmadds y familia: la multiplicación-suma del Gekko es fusionada de verdad, y fmaf da el mismo redondeo.
inline float fused_madd(float a, float b, float c) { return __builtin_fmaf(a, b, c); }
inline float fused_msub(float a, float b, float c) { return __builtin_fmaf(a, b, -c); }
inline float fused_nmsub(float a, float b, float c) { return -__builtin_fmaf(a, b, -c); }
inline float fused_nmadd(float a, float b, float c) { return -__builtin_fmaf(a, b, c); }
#endif
