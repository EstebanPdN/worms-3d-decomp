#include "w3d_ptr.h"
#line 1 "d24d_aim_update_80151a14.cpp"
// d24d: 0x80151a14 (612 bytes). Turn an actor towards its target: if the target's
// state (+220) is zero or +796 is clear, reset (0x8015286c), post message kind 16
// and stop. Otherwise take the vector to the target (+80) from the position (+560),
// compute the yaw error against +576, wrapped to [-pi, pi], and scale it by the rate
// (+328); -error * 100 goes to out->x. Unless 0x800154e0 reports the kind (+6), the
// yaw is stored and *out is reset from 0x8045e788. The pitch from the flat length is
// wrapped the same way and blended into the worm's +116 through the handle record.
// A flat vector is stored but not read back, as in the original. Built with
// -mps-float (two saved FPRs); the unflagged build differs only by the frame gap.
struct d24d_Vec3 { float x, y, z;
  d24d_Vec3() {}
  d24d_Vec3(const d24d_Vec3 &o) { x = o.x; y = o.y; z = o.z; }
  d24d_Vec3(float a, float b, float c) { x = a; y = b; z = c; }
  d24d_Vec3 operator-(const d24d_Vec3 &o) const { d24d_Vec3 r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
};
struct d24d_Handle { int value; unsigned key; d24d_Handle() { value = 0; key = 58280; } ~d24d_Handle(); };
struct d24d_WormInfo { char pad[80]; d24d_Vec3 target; char pad2[24]; float pitch; char pad3[100]; int state; };
struct d24d_AimActor { char pad[6]; unsigned short kind; char pad1[316]; int target; float rate; char pad2[228]; d24d_Vec3 pos; char pad3[4]; float yaw; char pad4[4]; int worm; char pad5[208]; int aim; };
extern "C" Ptr32<d24d_WormInfo> d24d_worm_info_800fc6dc(int);
extern "C" void d24d_reset_8015286c(Ptr32<d24d_AimActor>);
extern "C" Ptr32<void> d24d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" Ptr32<void> d24d_kind_message_80131b50(Ptr32<void>, int);
extern "C" int d24d_message_post_8016239c(Ptr32<void>);
extern "C" int d24d_kind_query_800154e0(unsigned short);
extern "C" float d24d_atan2_802e7e5c(float, float);
extern "C" float d24d_sqrt_802e82c0(float);
extern "C" Ptr32<d24d_WormInfo> d24d_worm_handle_800fc710(int, const d24d_Handle &);
extern Ptr32<void> d24d_arena_804b1754;
extern d24d_Vec3 d24d_zero_vector_8045e788[];
extern "C" void d24d_aim_update_80151a14(Ptr32<d24d_AimActor> self, Ptr32<d24d_Vec3> out) {
    if (d24d_worm_info_800fc6dc(self->target)->state == 0 || self->aim == 0) {
        d24d_reset_8015286c(self);
        d24d_message_post_8016239c(d24d_kind_message_80131b50(d24d_arena_alloc_801613f0(d24d_arena_804b1754, 12), 16));
        return;
    }
    d24d_Vec3 d = d24d_worm_info_800fc6dc(self->target)->target - self->pos;
    Ptr32<const d24d_Vec3> pd = &d;
    float a = d24d_atan2_802e7e5c(d.x, d.z);
    float t = a - self->yaw;
    while (t < -3.1415927f) t += 6.2831855f;
    while (t > 3.1415927f) t -= 6.2831855f;
    t *= self->rate;
    float yaw = a - t;
    out->x = -t * 100.0f;
    if (!d24d_kind_query_800154e0(self->kind)) {
        self->yaw = yaw;
        *out = d24d_zero_vector_8045e788[0];
    }
    float up = d.y;
    float fx = d.x, fz = pd->z, fy = 0.0f;
    d24d_Vec3 flat;
    flat.z = fz; flat.x = fx; flat.y = fy;
    float p = d24d_atan2_802e7e5c(up, d24d_sqrt_802e82c0(fx * fx + fy + fz * fz));
    while (p < -3.1415927f) p += 6.2831855f;
    while (p > 3.1415927f) p -= 6.2831855f;
    float pitch = p - (p - d24d_worm_info_800fc6dc(self->worm)->pitch) * self->rate;
    d24d_Handle h;
    d24d_worm_handle_800fc710(self->worm, h)->pitch = pitch;
}


