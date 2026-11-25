// libm por dirección original: newlib tiene una API double (0x802e5574-0x802e79e0) y otra float.
// Usa la libm de la plataforma. Las diferencias con la original se comprueban en el hito 7.
#include "w3d_ptr.h"
#include <math.h>
extern "C" {
double A802e5574(double x) { return acos(x); }
double A802e57f0(double x) { return asin(x); }
double A802e5a4c(double y, double x) { return atan2(y, x); }
double A802e5ccc(double x) { return exp(x); }
double A802e5f48(double x, double y) { return fmod(x, y); }
double A802e62d4(double x) { return log(x); }
double A802e6564(double x) { return log10(x); }
double A802e6690(double x, double y) { return pow(x, y); }
double A802e6ea8(double x) { return sqrt(x); }
double A802e710c(double x) { return atan(x); }
double A802e734c(double x) { return ceil(x); }
double A802e74b4(double x) { return cos(x); }
double A802e7594(double x) { return fabs(x); }
double A802e75d0(double x) { return floor(x); }
double A802e773c(double x, w3d_u32 e) { int k; double r = frexp(x, &k); *(int *)w3d::g2h(e) = k; return r; }
double A802e77f4(double x, int e) { return ldexp(x, e); }
double A802e787c(double x) { return sin(x); }
double A802e795c(double x) { return tan(x); }
float A802e79e0(float x) { return acosf(x); }
float A802e7c30(float x) { return asinf(x); }
float A802e7e5c(float y, float x) { return atan2f(y, x); }
float A802e8094(float x) { return expf(x); }
float A802e82c0(float x) { return sqrtf(x); }
float A802e83cc(float x) { return logf(x); }
float A802e83ec(float x) { return atanf(x); }
float A802e85fc(float x) { return ceilf(x); }
float A802e86d4(float x) { return cosf(x); }
float A802e87b0(float x) { return fabsf(x); }
float A802e87d4(float x) { return floorf(x); }
float A802e88ac(float x) { return sinf(x); }
float A802e8988(float x) { return tanf(x); }
int A802e8a08(float x) { return isfinite(x); }
double A802e8a28(double x, int e) { return scalbn(x, e); }
float A802e8b7c(float x, w3d_u32 ip) { float i; float r = modff(x, &i); *(float *)w3d::g2h(ip) = i; return r; }
float A802e8c1c(float x, int e) { return scalbnf(x, e); }
double A802e9e20(double x, double y) { return copysign(x, y); }
float A802e9e78(float x, float y) { return copysignf(x, y); }
}
