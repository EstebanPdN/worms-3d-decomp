/* Direction speed setup (0x800106e0): once the object is ready (0x8000f804),
 * looks up its tuning record (0x80341694, index 0), takes the speed (+188) or,
 * when it is zero, 0.05 times the fallback value (+184), normalizes the
 * direction vector (+36) in place, scales it by that speed and calls
 * 0x8000feb8 with the time plus 20. Field and type names are inferred from
 * the original instructions. The 0.0f, 0.05f, 1.0f and 20.0f constants
 * (0x8036a178..0x8036a187) are this function's own pool. Built with
 * -mps-float. */
struct V3 {
    float x, y, z;
    V3() {}
    V3(const V3 &v) : x(v.x), y(v.y), z(v.z) {}
    float LengthSquared() const { return z * z + (x * x + y * y); }
    void Scale(float s) { x *= s; y *= s; z *= s; }
};
inline V3 operator*(const V3 &v, float s) { V3 r; r.x = v.x * s; r.y = v.y * s; r.z = v.z * s; return r; }

struct DirectedObject {
    unsigned char unknown000[36];
    V3 direction;
};
struct DirectedTuning {
    unsigned char unknown000[184];
    float fallback_speed;
    float speed;
};

extern "C" int w3d_directed_ready_8000f804(DirectedObject *object, float);
extern "C" DirectedTuning *w3d_directed_tuning_80341694(DirectedObject *object, int index);
extern "C" float w3d_sqrt_802e82c0(float);
extern "C" int w3d_directed_apply_8000feb8(DirectedObject *object, float time);

extern "C" int w3d_d20a_direction_speed_800106e0(DirectedObject *self, float time)
{
    if (!w3d_directed_ready_8000f804(self, time))
        return 0;
    DirectedTuning *tuning = w3d_directed_tuning_80341694(self, 0);
    float speed = tuning->speed;
    if (speed == 0.0f)
        speed = tuning->fallback_speed * 0.05f;
    self->direction.Scale(1.0f / w3d_sqrt_802e82c0(self->direction.LengthSquared()));
    self->direction = self->direction * speed;
    return w3d_directed_apply_8000feb8(self, time + 20.0f);
}
