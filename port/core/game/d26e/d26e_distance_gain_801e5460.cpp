#include "w3d_ptr.h"
#line 1 "d26e_distance_gain_801e5460.cpp"
// (Worms 3D GameCube PAL, 0x801e5460).
//
// Distance gain of a 3D sound: emitter position (slot 14) against listener
// position (slot 17, kind 3), scaled by emitter slot 11. Below the near
// distance the gain is 1; beyond it falls linearly over near..far. The
// result times the listener volume (slot 16, kind 1) is clamped to [0, 1].
// Range getters 0x801df1c4 and 0x801df1bc are read here as near and far;
// those names are inferred.

extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
};
inline float Dist(const Vec &a, const Vec &b) {
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return sqrt_802e82c0(dx * dx + dy * dy + dz * dz);
}
inline const float &fmin(const float &a, const float &b) { return b < a ? b : a; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
struct Listener3D { Ptr32<Ptr32<void>> vt; };
struct Emitter { Ptr32<Ptr32<void>> vt; };
struct Range;
extern "C" float w3d_getf_801df1c4(Ptr32<Range>);
extern "C" float w3d_getf_801df1bc(Ptr32<Range>);
struct Player { char u[4]; Ptr32<Range> range; char v[4]; Ptr32<Listener3D> listener; };
typedef Ptr32<int (Ptr32<Listener3D>, int, Ptr32<Vec>)> GetFn;
typedef Ptr32<int (Ptr32<Listener3D>, int, Ptr32<float>)> GetVolFn;
typedef Ptr32<float (Ptr32<Emitter>)> FloatFn;
typedef Ptr32<void (Ptr32<Emitter>, Ptr32<Vec>)> VecFn;
extern "C" float w3d_d26e_distance_gain_801e5460(Ptr32<Player> self, Ptr32<Emitter> e) {
    Vec lpos, pos;
    ((VecFn)e->vt[14])(e, &pos);
    ((GetFn)self->listener->vt[17])(self->listener, 3, &lpos);
    float d = Dist(lpos, pos) * ((FloatFn)e->vt[11])(e);
    float gain;
    if (d < w3d_getf_801df1c4(self->range)) gain = 1.0f;
    else gain = 1.0f - (d - w3d_getf_801df1c4(self->range)) / (w3d_getf_801df1bc(self->range) - w3d_getf_801df1c4(self->range));
    float vol = 1.0f;
    ((GetVolFn)self->listener->vt[16])(self->listener, 1, &vol);
    vol *= gain;
    vol = fmax(vol, 0.0f);
    vol = fmin(vol, 1.0f);
    return vol;
}


