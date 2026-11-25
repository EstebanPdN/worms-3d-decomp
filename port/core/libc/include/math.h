#ifndef W3D_MATH_H
#define W3D_MATH_H
// Mismas firmas que la libm de cada plataforma salvo frexp/modf, adaptadas en core/libc.
#define HUGE_VAL (__builtin_huge_val())
#define PI_DUMMY 0
#include "w3d_libc_decl.h"
extern "C" {
double sin(double); double cos(double); double tan(double);
double asin(double); double acos(double); double atan(double); double atan2(double, double);
double sinh(double); double cosh(double); double tanh(double);
double sqrt(double); double exp(double); double log(double); double log10(double);
double pow(double, double); double fabs(double); double floor(double); double ceil(double); double fmod(double, double);
double ldexp(double, int);
float sinf(float); float cosf(float); float tanf(float);
float asinf(float); float acosf(float); float atanf(float); float atan2f(float, float);
float sqrtf(float); float expf(float); float logf(float); float log10f(float);
float powf(float, float); float fabsf(float); float floorf(float); float ceilf(float); float fmodf(float, float);
float ldexpf(float, int);
float fmaf(float, float, float);
double frexp(double, Ptr32<int>) W3D_LIBC(frexp);
double modf(double, Ptr32<double>) W3D_LIBC(modf);
float frexpf(float, Ptr32<int>) W3D_LIBC(frexpf);
float modff(float, Ptr32<float>) W3D_LIBC(modff);
}
#endif
