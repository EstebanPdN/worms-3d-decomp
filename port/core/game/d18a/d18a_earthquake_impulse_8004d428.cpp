#include "w3d_ptr.h"
#line 1 "d18a_earthquake_impulse_8004d428.cpp"
/* Earthquake impulse (0x8004d428). When an impulse is pending (+100), reads
 * the magnitude range on first use (maximum +272 still 0.0f) from the float
 * settings "Earthquake.ImpulseMagnitudeMax"/"...Min" through 0x800fc270,
 * builds a direction with random x and z in [-1, 1) and y = 0.5 from
 * 0x80162bc8, scales it by random * (maximum - minimum), stores the impulse
 * at +52 and clears the pending flag. The vector keeps a member-wise float
 * copy constructor and the default word-copy assignment. The two key strings
 * and the 0.0f/1.0f/0.5f literals are this unit's own read-only data
 * (0x803774bc..0x80377508). Names are inferred; offsets are observed. Built
 * with -mps-float (frame keeps 8 bytes below the save area for the saved
 * FPR). */
struct D18aVec3 {
    float x, y, z;
    D18aVec3() {}
    D18aVec3(const D18aVec3 &v) : x(v.x), y(v.y), z(v.z) {}
};

inline D18aVec3 operator*(const D18aVec3 &v, float s)
{
    D18aVec3 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}

struct D18aSettingKey {
    Ptr32<const char> name;
    template <class W3dU> D18aSettingKey(Ptr32<W3dU> w3d_p) : D18aSettingKey((const char *)w3d_p.get()) {}
 D18aSettingKey(const char *n) : name(n) {}
};

struct D18aEarthquake {
    unsigned char unknown00[52];
    D18aVec3 impulse;
    unsigned char unknown40[36];
    int pending;
    unsigned char unknown68[168];
    float magnitude_max;
    float magnitude_min;
};

extern "C" int d18a_read_float_setting_800fc270(const D18aSettingKey &key, Ptr32<float> value);
extern "C" float d18a_random_80162bc8();

extern "C" void w3d_d18a_earthquake_impulse_8004d428(Ptr32<D18aEarthquake> self)
{
    if (self->pending) {
        if (self->magnitude_max == 0.0f) {
            d18a_read_float_setting_800fc270(D18aSettingKey("Earthquake.ImpulseMagnitudeMax"), &self->magnitude_max);
            d18a_read_float_setting_800fc270(D18aSettingKey("Earthquake.ImpulseMagnitudeMin"), &self->magnitude_min);
        }
        D18aVec3 direction;
        direction.x = d18a_random_80162bc8() * 2.0f - 1.0f;
        direction.y = 0.5f;
        direction.z = d18a_random_80162bc8() * 2.0f - 1.0f;
        float magnitude = d18a_random_80162bc8() * (self->magnitude_max - self->magnitude_min);
        self->impulse = direction * magnitude;
        self->pending = 0;
    }
}

typedef char d18a_vec3_size[sizeof(D18aVec3) == 12 ? 1 : -1];
typedef char d18a_earthquake_size[sizeof(D18aEarthquake) == 280 ? 1 : -1];


