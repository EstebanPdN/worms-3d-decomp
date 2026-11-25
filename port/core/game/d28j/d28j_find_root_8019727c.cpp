#include "w3d_ptr.h"
#line 1 "d28j_find_root_8019727c.cpp"
// Polynomial and curve-parameter helpers of one source file, GWMP8P rev0
// 0x8019705c..0x801979fb, in original address order. Their literals are one
// contiguous pool: 0x803a84f8 (8-aligned, 0x8019705c) through 0x803a853f, with the
// conversion double of 0x801975b4 at 0x803a8530. No function here but the first can
// own its literals alone once 0x801975b4's double is in the object, because the pool
// is only 8-aligned at its head. 0x80197208, 0x80197244 and 0x801974f8 lie between
// these functions, have no literals, and stay in their admitted units.
extern float lbl_804ab6e4; /* epsilon margin (.sdata variable) */
extern "C" float fn_802e82c0(float value);
extern "C" void d19d_clamp_root_interval_80197128(Ptr32<void> self, Ptr32<float> first, Ptr32<float> second);

// 0x8019705c. Flips *b to 1 - *b, clamps the pair at zero, and when either leaves
// the unit range and the point is outside the region calls 0x80197128; flips *b back.
extern "C" void w3d_k8b_clamp_pair_8019705c(Ptr32<void> self, Ptr32<float> a, Ptr32<float> b)
{
    *b = 1.0f - *b;
    if (*a < 0.0f) *a = 0.0f;
    if (*b < 0.0f) *b = 0.0f;
    if (*a > 1.0f || *b > 1.0f) {
        float x = *a;
        float y = *b;
        if (x * ((x - 2.0f) + y) + y * (y - 2.0f) + 1.0f + lbl_804ab6e4 > 0.0f)
            d19d_clamp_root_interval_80197128(self, a, b);
    }
    *b = 1.0f - *b;
}

// d19d: 0x80197128 (224 bytes). Keep a pair of curve parameters inside the
// admissible region: for x = *first the quadratic t^2 + (x - 2) t + (x - 1)^2
// has real roots while x < 4/3; then *second is clamped (with the global
// margin `epsilon`) between the two roots (-(x - 2) +- sqrt(D)) / 2. At or
// beyond 4/3 the pair is reset to the double root (4/3, 1/3) minus the
// margin. 0x802e82c0 is the single-precision square root. Built with
// -mps-float (SN paired-single mode: one reserved 8-byte slot per saved FPR).
// Owns its float literal pool (4/3, 2, 1, 4, 0.5, 1/3).
extern "C" void d19d_clamp_root_interval_80197128(Ptr32<void> self, Ptr32<float> first, Ptr32<float> second)
{
    float x = *first;
    if (x + lbl_804ab6e4 < 1.3333334f) {
        float b = x - 2.0f;
        float c = x - 1.0f;
        float root = fn_802e82c0(b * b - c * 4.0f * c);
        float upper = (-b + root) * 0.5f;
        float y = *second;
        b = -b;
        if (y + lbl_804ab6e4 > upper) {
            *second = upper - lbl_804ab6e4;
        } else {
            float lower = (b - root) * 0.5f + lbl_804ab6e4;
            if (y < lower)
                *second = lower;
        }
    } else {
        *first = 1.3333334f - lbl_804ab6e4;
        *second = 0.33333334f - lbl_804ab6e4;
    }
}

// Brent's root finder (Numerical Recipes zbrent), GWMP8P rev0 0x8019727c.
// Finds a root of a polynomial given a bracket a, b with values fa, fb and a
// tolerance tol: inverse quadratic or secant steps when acceptable, bisection
// otherwise. The polynomial is evaluated by 0x80197244. Written with labels,
// as the original keeps the constants in place in the loop, and the bisection
// fallback appears twice and is merged by cross-jumping. Returns the root.

struct Poly { Ptr32<float> coeffs; int degree; Poly(Ptr32<float> c, int d) : coeffs(c), degree(d) {} };
extern "C" float eval_80197244(Ptr32<float>, int, float);
extern "C" float d28j_find_root_8019727c(float a, float b, Ptr32<Poly> poly, float fa, float fb, float tol) {
    float eps = lbl_804ab6e4;
    float c, fc, d, e, k;
reset:
    d = b - a;
    c = a;
    fc = fa;
    e = d;
    k = eps + eps;
top:
            if (__builtin_fabsf(fc) < __builtin_fabsf(fb)) {
                a = b;
                fa = fb;
                b = c;
                fb = fc;
                c = a;
                fc = fa;
            }
            float t = k * __builtin_fabsf(b) + tol * 0.5f;
            float m = (c - b) * 0.5f;
            bool more = __builtin_fabsf(m) > t && fb != 0.0f;
            if (!more) goto done;
            if (__builtin_fabsf(e) < t || __builtin_fabsf(fa) <= __builtin_fabsf(fb)) {
                d = m;
                e = m;
            } else {
                float s = fb / fa;
                float p, q;
                if (a == c) {
                    p = (m + m) * s;
                    q = 1.0f - s;
                } else {
                    float r = fb / fc;
                    q = fa / fc;
                    p = s * ((m + m) * q * (q - r) - (b - a) * (r - 1.0f));
                    q = (q - 1.0f) * (r - 1.0f) * (s - 1.0f);
                }
                if (p > 0.0f) q = -q;
                else p = -p;
                s = e;
                e = d;
                if (p + p < m * 3.0f * q - __builtin_fabsf(t * q) && p < __builtin_fabsf(s * 0.5f * q)) {
                    d = p / q;
                } else {
                    d = m;
                    e = m;
                }
            }
            a = b;
            fa = fb;
            if (__builtin_fabsf(d) > t) b += d;
            else if (m > 0.0f) b += t;
            else b -= t;
            fb = eval_80197244(poly->coeffs, poly->degree, b);
            if (fb * (fc / __builtin_fabsf(fc)) > 0.0f) goto reset;
            goto top;
done:
    return b;
}

// GWMP8P rev0 0x801975b4. Real roots of a polynomial inside an interval: normalises
// the coefficients, solves the derivative recursively, and brackets a root between
// consecutive critical points with 0x801974f8. Returns the count, -1 if the polynomial
// is negligible. Local pointers to the three stack arrays are as in the draft that
// matches (d28j); field names and the self type are inferred.
extern "C" float w3d_cc24b_root_bracket_801974f8(float, float, Ptr32<Poly>, float);
struct Self;
extern "C" int d43p_polynomial_real_roots_801975b4(Ptr32<Self> self, Ptr32<const float> c, int n, float lo, bool incLo, float hi, bool incHi, Ptr32<float> out) {
    float x1 = 0.0f, y1 = 0.0f;
    float sum = 0.0f;
    int i;
    for (i = 0; i < n + 1; ++i) sum += __builtin_fabsf(c[i]);
    float tol = (__builtin_fabsf(lo) + __builtin_fabsf(hi)) * (float)(n + 1) * lbl_804ab6e4;
    if (sum <= tol) return -1;
    float ncs[22], derivs[22], rootss[22];
    Ptr32<float> nc = ncs; Ptr32<float> deriv = derivs; Ptr32<float> roots = rootss;
    for (i = 0; i < n + 1; ++i) nc[i] = 1.0f / sum * c[i];
    while (__builtin_fabsf(nc[n]) < tol) --n;
    int count = 0;
    if (n == 0) return 0;
    if (n == 1) {
        out[0] = -nc[0] / nc[1];
        bool above = lo < (incLo ? out[0] + tol : out[0] - tol);
        bool below = hi > (incHi ? out[0] - tol : out[0] + tol);
        count = above && below;
        if (count) {
            if (incLo && out[0] < lo) out[0] = lo;
            else if (incHi && out[0] > hi) out[0] = hi;
        }
        return count;
    }
    Poly poly(nc, n);
    for (i = 1; i <= n; ++i) deriv[i - 1] = (float)i * nc[i];
    int nroots = d43p_polynomial_real_roots_801975b4(self, deriv, n - 1, lo, false, hi, false, roots);
    if (nroots == -1) return 0;
    bool skip = false;
    for (i = 0; i <= nroots; ++i) {
        float x0, y0;
        if (count > n) return count;
        if (i == 0) {
            x0 = lo;
            y0 = eval_80197244(nc, n, x0);
            if (__builtin_fabsf(y0) <= tol && incLo) {
                out[count] = x0;
                ++count;
            }
        } else {
            x0 = x1;
            y0 = y1;
        }
        if (i == nroots) {
            x1 = hi;
            skip = false;
        } else x1 = roots[i];
        y1 = eval_80197244(nc, n, x1);
        if (skip) {
            skip = false;
        } else if (__builtin_fabsf(y1) < tol) {
            if (i != nroots || incHi) {
                out[count] = x1;
                ++count;
                skip = true;
            }
        } else if ((y0 < 0.0f && y1 > 0.0f) || (y0 > 0.0f && y1 < 0.0f)) {
            float r = w3d_cc24b_root_bracket_801974f8(x0, x1, &poly, 0.0f);
            out[count] = r;
            ++count;
            if (count > 1 && out[count - 2] >= out[count - 1] - tol) {
                out[count - 2] = (out[count - 2] + out[count - 1]) * 0.5f;
                --count;
            }
        }
    }
    return count;
}


