#include "w3d_ptr.h"
#line 1 "d40m_box3_box3_test_800c59cc.cpp"
// GWMP8P rev0 0x800c59cc. Oriented box overlap test, the Box3/Box3 test of
// Eberly's Magic Software library: separating axes A0-A2 and B0-B2, early
// true when a pair of axes is parallel beyond the 0.999999 cutoff, then the
// nine cross axes. Box view: word, centre, three axes, extents.
struct Vec { float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float Dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    const float &operator[](int i) const { return (&x)[i]; }
};
inline Vec operator-(const Vec &a, const Vec &b) { return Vec(a.x - b.x, a.y - b.y, a.z - b.z); }
struct Box { int unknown0; Vec c; Vec u[3]; Vec e; };
extern "C" int d40m_box3_box3_test_800c59cc(Ptr32<const Box> a, Ptr32<const Box> b) {
    Ptr32<const Vec> akA = a->u;
    Ptr32<const Vec> akB = b->u;
    Ptr32<const float> afEA = &a->e.x;
    Ptr32<const float> afEB = &b->e.x;
    const Vec &c0 = a->c; const Vec &c1 = b->c;
    Vec kD;
    Vec kT = c1 - c0;
    kD.x = kT.x; kD.y = kT.y; kD.z = kT.z;
    float aafC[3][3];
    float aafAbsC[3][3];
    float fR0, fR1, fR, fR01;
    int bPar = 0;
    int i;
    for (i = 0; i < 3; i++) {
        aafC[0][i] = akA[0].Dot(akB[i]);
        aafAbsC[0][i] = __builtin_fabsf(aafC[0][i]);
        if (aafAbsC[0][i] > 0.999999f) bPar = 1;
    }
    kT.x = akA[0].Dot(kD);
    fR = __builtin_fabsf(kT.x);
    fR1 = afEB[0] * aafAbsC[0][0] + afEB[1] * aafAbsC[0][1] + afEB[2] * aafAbsC[0][2];
    fR01 = afEA[0] + fR1;
    if (fR > fR01) return 0;
    for (i = 0; i < 3; i++) {
        aafC[1][i] = akA[1].Dot(akB[i]);
        aafAbsC[1][i] = __builtin_fabsf(aafC[1][i]);
        if (aafAbsC[1][i] > 0.999999f) bPar = 1;
    }
    kT.y = akA[1].Dot(kD);
    fR = __builtin_fabsf(kT.y);
    fR1 = afEB[0] * aafAbsC[1][0] + afEB[1] * aafAbsC[1][1] + afEB[2] * aafAbsC[1][2];
    fR01 = afEA[1] + fR1;
    if (fR > fR01) return 0;
    for (i = 0; i < 3; i++) {
        aafC[2][i] = akA[2].Dot(akB[i]);
        aafAbsC[2][i] = __builtin_fabsf(aafC[2][i]);
        if (aafAbsC[2][i] > 0.999999f) bPar = 1;
    }
    kT.z = akA[2].Dot(kD);
    fR = __builtin_fabsf(kT.z);
    fR1 = afEB[0] * aafAbsC[2][0] + afEB[1] * aafAbsC[2][1] + afEB[2] * aafAbsC[2][2];
    fR01 = afEA[2] + fR1;
    if (fR > fR01) return 0;
    fR = __builtin_fabsf(akB[0].Dot(kD));
    fR0 = afEA[0] * aafAbsC[0][0] + afEA[1] * aafAbsC[1][0] + afEA[2] * aafAbsC[2][0];
    fR01 = fR0 + afEB[0];
    if (fR > fR01) return 0;
    fR = __builtin_fabsf(akB[1].Dot(kD));
    fR0 = afEA[0] * aafAbsC[0][1] + afEA[1] * aafAbsC[1][1] + afEA[2] * aafAbsC[2][1];
    fR01 = fR0 + afEB[1];
    if (fR > fR01) return 0;
    fR = __builtin_fabsf(akB[2].Dot(kD));
    fR0 = afEA[0] * aafAbsC[0][2] + afEA[1] * aafAbsC[1][2] + afEA[2] * aafAbsC[2][2];
    fR01 = fR0 + afEB[2];
    if (fR > fR01) return 0;
    if (bPar) return 1;
    fR = __builtin_fabsf(kT.z * aafC[1][0] - kT.y * aafC[2][0]);
    fR0 = afEA[1] * aafAbsC[2][0] + afEA[2] * aafAbsC[1][0];
    fR1 = afEB[1] * aafAbsC[0][2] + afEB[2] * aafAbsC[0][1];
    fR01 = fR0 + fR1;
    if (fR > fR01) return 0;
    fR = __builtin_fabsf(kT.z * aafC[1][1] - kT.y * aafC[2][1]);
    fR0 = afEA[1] * aafAbsC[2][1] + afEA[2] * aafAbsC[1][1];
    fR1 = afEB[0] * aafAbsC[0][2] + afEB[2] * aafAbsC[0][0];
    fR01 = fR0 + fR1;
    if (fR > fR01) return 0;
    fR = __builtin_fabsf(kT.z * aafC[1][2] - kT.y * aafC[2][2]);
    fR0 = afEA[1] * aafAbsC[2][2] + afEA[2] * aafAbsC[1][2];
    fR1 = afEB[0] * aafAbsC[0][1] + afEB[1] * aafAbsC[0][0];
    fR01 = fR0 + fR1;
    if (fR > fR01) return 0;
    fR = __builtin_fabsf(kT.x * aafC[2][0] - kT.z * aafC[0][0]);
    fR0 = afEA[0] * aafAbsC[2][0] + afEA[2] * aafAbsC[0][0];
    fR1 = afEB[1] * aafAbsC[1][2] + afEB[2] * aafAbsC[1][1];
    fR01 = fR0 + fR1;
    if (fR > fR01) return 0;
    fR = __builtin_fabsf(kT.x * aafC[2][1] - kT.z * aafC[0][1]);
    fR0 = afEA[0] * aafAbsC[2][1] + afEA[2] * aafAbsC[0][1];
    fR1 = afEB[0] * aafAbsC[1][2] + afEB[2] * aafAbsC[1][0];
    fR01 = fR0 + fR1;
    if (fR > fR01) return 0;
    fR = __builtin_fabsf(kT.x * aafC[2][2] - kT.z * aafC[0][2]);
    fR0 = afEA[0] * aafAbsC[2][2] + afEA[2] * aafAbsC[0][2];
    fR1 = afEB[0] * aafAbsC[1][1] + afEB[1] * aafAbsC[1][0];
    fR01 = fR0 + fR1;
    if (fR > fR01) return 0;
    fR = __builtin_fabsf(kT.y * aafC[0][0] - kT.x * aafC[1][0]);
    fR0 = afEA[0] * aafAbsC[1][0] + afEA[1] * aafAbsC[0][0];
    fR1 = afEB[1] * aafAbsC[2][2] + afEB[2] * aafAbsC[2][1];
    fR01 = fR0 + fR1;
    if (fR > fR01) return 0;
    fR = __builtin_fabsf(kT.y * aafC[0][1] - kT.x * aafC[1][1]);
    fR0 = afEA[0] * aafAbsC[1][1] + afEA[1] * aafAbsC[0][1];
    fR1 = afEB[0] * aafAbsC[2][2] + afEB[2] * aafAbsC[2][0];
    fR01 = fR0 + fR1;
    if (fR > fR01) return 0;
    fR = __builtin_fabsf(kT.y * aafC[0][2] - kT.x * aafC[1][2]);
    fR0 = afEA[0] * aafAbsC[1][2] + afEA[1] * aafAbsC[0][2];
    fR1 = afEB[0] * aafAbsC[2][1] + afEB[1] * aafAbsC[2][0];
    fR01 = fR0 + fR1;
    if (fR > fR01) return 0;
    return 1;
}


