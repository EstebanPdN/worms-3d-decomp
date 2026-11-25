// Solo en 3DS, incluido con -include. ARM11 (VFPv2) no tiene fma, y __builtin_fmaf acaba en una llamada a fmaf de newlib,
// que hace esto mismo en doble: el producto de dos float es exacto en doble, así que el redondeo es el del fmadds del Gekko
// salvo en el doble redondeo de la suma, igual que antes. En línea se ahorra la llamada (2,5 % del hilo del juego, perfil pr2).
#pragma once
#if defined(__arm__) && !defined(__ARM_FEATURE_FMA)
static inline __attribute__((always_inline)) float w3d_fmaf_arm(float a, float b, float c) {
    return (float)((double)a * (double)b + (double)c);
}
#define __builtin_fmaf w3d_fmaf_arm
#endif
