#include "w3d_ptr.h"
#line 1 "k2a_scale_clamp_80097e7c.cpp"
template <class T> inline const T &k2a_max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &k2a_min(const T &a, const T &b) { return a < b ? a : b; }
template <class T> inline const T &k2a_clamp(const T &v, const T &lo, const T &hi) { return k2a_max(k2a_min(v, hi), lo); }

extern const float w3d_f32_8037f710[];
extern const float w3d_f32_8037f714[];
extern const float w3d_f32_8037f718[];
extern const float w3d_f32_8037f71c[];
extern const float w3d_f32_8037f720[];

extern "C" float k2a_scale_clamp_80097e7c(float x)
{
    float value = ((x * w3d_f32_8037f710[0] + w3d_f32_8037f710[0]) * w3d_f32_8037f714[0]) / w3d_f32_8037f718[0];
    float low = w3d_f32_8037f71c[0];
    float high = w3d_f32_8037f720[0];
    value = k2a_clamp(value, low, high);
    return value;
}


