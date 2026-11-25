#include "w3d_ptr.h"
#line 1 "d15d_rotated_velocity_8014fb40.cpp"
/* Rotated actor velocity recovered from 0x8014fb40 (SN ProDG g++ 2.95).
 * D15dVec3's default constructor is the original empty routine 0x80343740.
 * The two pool constants (0x803a17b0 zero, 0x803a17b4) are original external
 * objects, declared without const because the original reloads them after the
 * call. The row accessor returns a reference, which keeps each row address in
 * a register as in the original. Layouts are partial observed views. */
struct D15dVec3 {
    float x, y, z;
    D15dVec3();
};
struct D15dAxis { float x, y, z; };
struct D15dTransform { D15dAxis axis[3]; D15dVec3 position; };
struct D15dRow { float x, y, z, w; };
extern "C" float w3d_f32_803a17b0[], w3d_f32_803a17b4[];
struct D15dMatrix4 {
    D15dRow row[4];
    const D15dRow &Row(int i) const { return row[i]; }
    D15dMatrix4(Ptr32<const D15dAxis> axis, const D15dVec3 &p)
    {
        row[0].x = axis[0].x; row[0].y = axis[0].y; row[0].z = axis[0].z; row[0].w = w3d_f32_803a17b0[0];
        row[1].x = axis[1].x; row[1].y = axis[1].y; row[1].z = axis[1].z; row[1].w = w3d_f32_803a17b0[0];
        row[2].x = axis[2].x; row[2].y = axis[2].y; row[2].z = axis[2].z; row[2].w = w3d_f32_803a17b0[0];
        row[3].x = p.x; row[3].y = p.y; row[3].z = p.z; row[3].w = w3d_f32_803a17b4[0];
    }
};
struct D15dActor {
    unsigned char pad000[576];
    float heading;
    unsigned char pad244[676 - 580];
    float velocity[3];
    unsigned char pad2b0[760 - 688];
    int mode;
};
struct D15dInput;
extern "C" {
void w3d_s21_construct_801f7538(Ptr32<D15dTransform>, float, float, float, float);
extern Ptr32<D15dInput> w3d_global_804afde8;
Ptr32<const D15dVec3> w3d_auto_80178ec4(Ptr32<D15dInput>);
void w3d_motion_set_actor_value(Ptr32<D15dActor>, int);
void d15d_actor_apply_rotated_velocity_8014fb40(Ptr32<D15dActor> self);
}
static inline void d15d_rotate_direction(Ptr32<float> out, const D15dMatrix4 &m, Ptr32<const D15dVec3> v)
{
    out[0] = v->x * m.Row(0).x + v->y * m.Row(1).x + v->z * m.Row(2).x;
    out[1] = v->x * m.Row(0).y + v->y * m.Row(1).y + v->z * m.Row(2).y;
    out[2] = v->x * m.Row(0).z + v->y * m.Row(1).z + v->z * m.Row(2).z;
}

void d15d_actor_apply_rotated_velocity_8014fb40(Ptr32<D15dActor> self)
{
    D15dTransform rotation;
    const D15dVec3 &position = rotation.position;
    Ptr32<D15dAxis> axis = rotation.axis;
    w3d_s21_construct_801f7538(&rotation, w3d_f32_803a17b0[0], w3d_f32_803a17b4[0], w3d_f32_803a17b0[0], self->heading);
    Ptr32<const D15dVec3> input = w3d_auto_80178ec4(w3d_global_804afde8);
    D15dMatrix4 full(axis, position);
    d15d_rotate_direction(self->velocity, full, input);
    self->mode = 6;
    w3d_motion_set_actor_value(self, 32);
}


