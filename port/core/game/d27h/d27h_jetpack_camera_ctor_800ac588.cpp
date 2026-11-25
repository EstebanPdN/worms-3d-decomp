#include "w3d_ptr.h"
#line 1 "d27h_jetpack_camera_ctor_800ac588.cpp"
// GWMP8P rev0 0x800ac588. Jetpack camera constructor. Names are inferred.
// Runs the base camera constructor with kind 9, sets the table pointer,
// clears the setting references +76..+128 and binds each to its named
// setting. The reference held from the start of the body is witnessed by the
// saved register holding self+88.
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> name; };
struct Ref {
    Ptr32<Object> value;
    Ref() { value = 0; }
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
};
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<void>);
extern "C" int write_setting_800fc43c(Ptr32<Key>, int);
static inline void assign(Ptr32<Object> &slot, Ptr32<Object> value) {
    if (value) value->vtable->retain(value);
    if (slot) slot->vtable->release(slot);
    slot = value;
}
extern "C" Ptr32<Object> cast_80342a74(Ptr32<Object>);
static inline void load_80342a74(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, cast_80342a74(found.value));
}
struct Camera {
    unsigned char unknown00[72];
    Ptr32<void> vtable;  // +72
    Ptr32<Object> f76;  // +76 Camera.Jetpack.DistFromObject
    Ptr32<Object> f80;  // +80 Camera.Jetpack.LookAboveObject
    Ptr32<Object> f84;  // +84 Camera.Jetpack.DefaultHeight
    Ptr32<Object> f88;  // +88 Camera.Jetpack.PosUpdateSpeed
    Ptr32<Object> f92;  // +92 Camera.Jetpack.LookUpdateSpeed
    Ptr32<Object> f96;  // +96 Camera.Jetpack.UpUpdateSpeed
    Ptr32<Object> f100;  // +100 Camera.Jetpack.LookAheadScale
    Ptr32<Object> f104;  // +104 Camera.Jetpack.LookAheadSpeed
    Ptr32<Object> f108;  // +108 Camera.Jetpack.MaxLkAheadDist
    Ptr32<Object> f112;  // +112 Camera.Jetpack.VelocityScale
    Ptr32<Object> f116;  // +116 Camera.Jetpack.MinDistance
    Ptr32<Object> f120;  // +120 Camera.Jetpack.DefaultDistance
    Ptr32<Object> f124;  // +124 Camera.Jetpack.AbsoluteMinDist
    Ptr32<Object> f128;  // +128 Camera.Jetpack.AbsoluteMaxDist
};
extern unsigned char vtable_8040f6c0[];
extern "C" int base_8015a0d4(Ptr32<Camera>, Ptr32<const char>, int);
extern const char n_80381e38[];  // "Camera.Jetpack.DistFromObject"
extern const char n_80381e58[];  // "Camera.Jetpack.LookAboveObject"
extern const char n_80381e78[];  // "Camera.Jetpack.DefaultHeight"
extern const char n_80381e98[];  // "Camera.Jetpack.PosUpdateSpeed"
extern const char n_80381eb8[];  // "Camera.Jetpack.LookUpdateSpeed"
extern const char n_80381ed8[];  // "Camera.Jetpack.UpUpdateSpeed"
extern const char n_80381ef8[];  // "Camera.Jetpack.LookAheadScale"
extern const char n_80381f18[];  // "Camera.Jetpack.LookAheadSpeed"
extern const char n_80381f38[];  // "Camera.Jetpack.MaxLkAheadDist"
extern const char n_80381f58[];  // "Camera.Jetpack.VelocityScale"
extern const char n_80381f78[];  // "Camera.Jetpack.MinDistance"
extern const char n_80381f94[];  // "Camera.Jetpack.DefaultDistance"
extern const char n_80381fb4[];  // "Camera.Jetpack.AbsoluteMinDist"
extern const char n_80381fd4[];  // "Camera.Jetpack.AbsoluteMaxDist"
extern "C" Ptr32<Camera> d27h_jetpack_camera_ctor_800ac588(Ptr32<Camera> self, Ptr32<const char> name) {
    base_8015a0d4(self, name, 9);
    Ptr32<Object> &up = self->f88;
    self->vtable = vtable_8040f6c0;
    self->f76 = 0;
    self->f80 = 0;
    self->f84 = 0;
    self->f88 = 0;
    self->f92 = 0;
    self->f96 = 0;
    self->f100 = 0;
    self->f104 = 0;
    self->f108 = 0;
    self->f112 = 0;
    self->f116 = 0;
    self->f120 = 0;
    self->f124 = 0;
    self->f128 = 0;
    load_80342a74(self->f76, n_80381e38);
    load_80342a74(self->f80, n_80381e58);
    load_80342a74(self->f84, n_80381e78);
    load_80342a74(up, n_80381e98);
    load_80342a74(self->f92, n_80381eb8);
    load_80342a74(self->f96, n_80381ed8);
    load_80342a74(self->f100, n_80381ef8);
    load_80342a74(self->f104, n_80381f18);
    load_80342a74(self->f108, n_80381f38);
    load_80342a74(self->f112, n_80381f58);
    load_80342a74(self->f116, n_80381f78);
    load_80342a74(self->f120, n_80381f94);
    load_80342a74(self->f124, n_80381fb4);
    load_80342a74(self->f128, n_80381fd4);
    return self;
}


