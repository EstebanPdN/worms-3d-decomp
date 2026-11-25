#include "w3d_ptr.h"
extern "C" void w3d_hud_aim_observe(float,int);
#line 1 "d11c_tilt_update_80028d10_v0.cpp"
// d11c: 0x80028d10 (256 bytes), update a clamped tilt angle and hand it to a
// handle as a rotation vector.
// Observed in the original DOL: nothing happens unless the word at +68 is
// nonzero. The object at +80 is cast through 0x803426b4 and indexed through
// 0x80178c48; an index other than -1 copies the float at +116 of the record
// from 0x800fc6dc into the angle at +72. When 0x80178c48 of the object at +116
// returns 1 the angle becomes 0x8036cea8 (0.0f) minus itself. The angle is
// clamped through reference-returning min/max helpers to [0x8036ceac,
// 0x8036ceb0] (-1.5707964f, 1.5707964f, decoded from the DOL; both bounds live
// in stack temporaries), stored back, and a stack vector (0.0f, 0.0f, -angle)
// filled through a pointer goes with 0 to virtual slot +80 of the handle at
// +40. All names and views are inferred; unknown words are partial views.
struct d11c_Vec3 { float x, y, z; };
struct d11c_Object;
struct d11c_Record { unsigned char unknown00[116]; float angle; };
struct d11c_Handle;
struct d11c_HandleVtable {
    Ptr32<void> unknown00[20];
    Ptr32<void (Ptr32<d11c_Handle>, const d11c_Vec3 &, int)> set_rotation;   // +80
};
struct d11c_Handle { Ptr32<d11c_HandleVtable> vtable; };
struct d11c_Tilt {
    unsigned char unknown00[40];
    Ptr32<d11c_Handle> handle;                 // +40
    unsigned char unknown2c[24];
    int enabled;                         // +68
    float angle;                         // +72
    unsigned char unknown4c[4];
    Ptr32<d11c_Object> source;                 // +80
    unsigned char unknown54[32];
    Ptr32<d11c_Object> mode;                   // +116
};
extern "C" {
Ptr32<d11c_Object> d11c_object_cast_803426b4(Ptr32<d11c_Object>);
int d11c_reference_index_80178c48(Ptr32<d11c_Object>);
Ptr32<d11c_Record> d11c_index_query_800fc6dc(int);
extern const float d11c_f32_8036cea8[], d11c_f32_8036ceac[], d11c_f32_8036ceb0[];
}
template <class T> inline const T &d11c_min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> inline const T &d11c_max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &d11c_clamp(const T &value, const T &low, const T &high) { return d11c_max(d11c_min(high, value), low); }
extern "C" void d11c_tilt_update_80028d10(Ptr32<d11c_Tilt> self) {
    if (self->enabled == 0) { w3d_hud_aim_observe(0,0);return; }
    int index = d11c_reference_index_80178c48(d11c_object_cast_803426b4(self->source));
    if (index != -1)
        self->angle = d11c_index_query_800fc6dc(index)->angle;
    if (d11c_reference_index_80178c48(self->mode) == 1)
        self->angle = d11c_f32_8036cea8[0] - self->angle;
    float low = d11c_f32_8036ceac[0];
    float high = d11c_f32_8036ceb0[0];
    float angle = d11c_clamp(self->angle, low, high);
    self->angle = angle;
    w3d_hud_aim_observe(angle,1);
    d11c_Vec3 rotation;
    Ptr32<d11c_Vec3> p = &rotation;
    p->x = d11c_f32_8036cea8[0];
    p->y = d11c_f32_8036cea8[0];
    p->z = -angle;
    self->handle->vtable->set_rotation(self->handle, rotation, 0);
}


