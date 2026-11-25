// d21c: 0x800dc244 (408 bytes). Update an owner's attached effect (+156)
// from a position and a velocity. Nothing happens without an effect.
// Otherwise the position is passed to slot 14 with key 3, the speed (length
// of the velocity) is limited to 0.05 and turned into a ratio of that limit,
// the integer property 12 is read through slot 15, raised by
// ratio * 0.7 * itself and written as property 2 through slot 12, and the
// ratio clamped to [0.2, 1] is written as float property 1 through slot 13.
// The slots are read from the effect's four-byte virtual table and called
// explicitly. Offsets are observed; meanings are inferred.
// Built with -mps-float: the ratio stays in f31 across the calls and the
// unflagged build differs only by the 8-byte frame gap below the register
// save area. The speed comes from an inline length() member (a separate
// squared-norm helper plus the root call stores the speed after the address
// of its slot is formed); the clamp is an inline helper taking
// (value, lower, upper), whose reference parameters fix the stack slots of
// lower (+24) and upper (+28), with min(upper, value) before max(..., lower).
// The 0.05 limit (0x803898e4) sits 4 bytes past an 8-byte boundary and stays
// external; the unit owns the aligned tail 0x803898e8..0x80389900
// (0.7, padding, the int-to-float conversion constant, 0.2, 1.0).
namespace d21c_effect {

extern "C" float w3d_sqrt_802e82c0(float value);

struct Vec3 {
    float x, y, z;
    float length() const { return w3d_sqrt_802e82c0(x * x + y * y + z * z); }
};

struct Effect {
    void **vtable;
};

struct Owner {
    unsigned char unknown000[156];
    Effect *effect;                      // +156
};

typedef void (*SetVectorFn)(Effect *, int, const Vec3 *);
typedef int (*GetIntFn)(Effect *, int, int *);
typedef int (*SetIntFn)(Effect *, int, int);
typedef int (*SetFloatFn)(Effect *, int, float);

extern "C" const float w3d_f32_803898e4[];   // 0.05

inline const float &min(const float &a, const float &b) { return b < a ? b : a; }
inline const float &max(const float &a, const float &b) { return a < b ? b : a; }
inline const float &clamp(const float &value, const float &lower, const float &upper)
{
    return max(min(upper, value), lower);
}

} // namespace d21c_effect

using namespace d21c_effect;

extern "C" void d21c_effect_motion_800dc244(Owner *self, const Vec3 *position, const Vec3 *velocity)
{
    if (self->effect) {
        ((SetVectorFn)self->effect->vtable[14])(self->effect, 3, position);
        float speed = velocity->length();
        float limit = w3d_f32_803898e4[0];
        speed = min(speed, limit);
        float ratio = speed / limit;
        int value;
        ((GetIntFn)self->effect->vtable[15])(self->effect, 12, &value);
        value += (int)((ratio * 0.7f) * (float)value);
        ((SetIntFn)self->effect->vtable[12])(self->effect, 2, value);
        float amount = ratio;
        float lower = 0.2f, upper = 1.0f;
        amount = clamp(amount, lower, upper);
        ((SetFloatFn)self->effect->vtable[13])(self->effect, 1, amount);
    }
}
