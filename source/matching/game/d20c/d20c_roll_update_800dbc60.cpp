// d20c: 0x800dbc60 (248 bytes). Update a roll value (+132) from the owner's
// horizontal speed: the length of the velocity (+108) with its y component
// replaced by 0 is multiplied by (2 * tick / pi + 1) * 0.0001 and added to
// the roll, the roll is then damped by 1% (roll += roll * -0.01) and clamped
// to [-5, 5] through reference-returning max/min helpers. Offsets are
// observed; meanings are inferred.
// Built with -mps-float: the tick stays in f31 across the square-root call
// and the unflagged build differed only by the 8-byte frame gap below the
// register save area. The two compound assignments keep the sum in f31 and
// the damped value in f0, as in the original; a named temporary or plain
// assignments swap the registers. The unit owns its literal pool
// 0x8038987c..0x80389898 (0, pi, 1, 0.0001, -0.01, -5, 5) in first-use
// order; an external 0.0f changes the schedule. 0x80389878 belongs to
// 0x800dbaf4.
namespace d20c_roll {

extern "C" float w3d_sqrt_802e82c0(float value);

struct Vec3 {
    float x, y, z;
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    float length() const { return w3d_sqrt_802e82c0(x * x + y * y + z * z); }
};

struct Owner {
    unsigned char unknown00[108];
    Vec3 velocity;                       // +108
    unsigned char unknown120[12];
    float roll;                          // +132
};

inline const float &maximum(const float &a, const float &b) { return a < b ? b : a; }
inline const float &minimum(const float &a, const float &b) { return b < a ? b : a; }

extern "C" void d20c_roll_update_800dbc60(Owner *self, float tick)
{
    Vec3 horizontal(self->velocity.x, 0.0f, self->velocity.z);
    float speed = horizontal.length();
    tick = tick / 3.14159274f;
    self->roll += ((tick + tick + 1.0f) * speed) * 0.0001f;
    self->roll += self->roll * -0.01f;
    float lower = -5.0f;
    self->roll = maximum(self->roll, lower);
    float upper = 5.0f;
    self->roll = minimum(self->roll, upper);
}

}
