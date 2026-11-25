#include "w3d_ptr.h"
#line 1 "d27c_orbit_camera_construct_800d6b44.cpp"
// d27c: 0x800d6b44. Orbit camera constructor: base constructor 0x8015a0d4 with type 4, vtable 0x8040fd38 at +72, clears, then resolves the retained settings Camera.Orbit.Speed, AdditionalRadius, Height, Water.Level and IgnoreInput. Names are inferred.
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
static inline void assign(Ptr32<Object> &slot, Ptr32<Object> value) {
    if (value) value->vtable->retain(value);
    if (slot) slot->vtable->release(slot);
    slot = value;
}

struct Orbit {
    unsigned char u0[72];
    Ptr32<const void> vtable;
    Ptr32<Object> speed; Ptr32<Object> radius; Ptr32<Object> height; Ptr32<Object> ignore; Ptr32<Object> level;
};
extern "C" int base_8015a0d4(Ptr32<Orbit>, Ptr32<const char>, int);
extern "C" Ptr32<Object> as_float_80342a74(Ptr32<Object>);
extern "C" Ptr32<Object> as_int_80342a78(Ptr32<Object>);
extern Ptr32<const void> const vtable_8040fd38[];
extern const char n_80389028[], n_8038903c[], n_8038905c[], n_80389070[], n_8038907c[];
static inline void load_float(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, as_float_80342a74(found.value));
}
static inline void load_int(Ptr32<Object> &slot, Ptr32<const char> name) {
    Ref found;
    Key key;
    key.name = name;
    read_setting_800fc1b0(&key, &found);
    assign(slot, as_int_80342a78(found.value));
}
extern "C" Ptr32<Orbit> d27c_orbit_camera_construct_800d6b44(Ptr32<Orbit> self, Ptr32<const char> name) {
    base_8015a0d4(self, name, 4);
    Ptr32<Object> &level = self->level;
    self->vtable = vtable_8040fd38;
    self->speed = 0;
    self->radius = 0;
    self->height = 0;
    self->ignore = 0;
    self->level = 0;
    load_float(self->speed, n_80389028);
    load_float(self->radius, n_8038903c);
    load_float(self->height, n_8038905c);
    load_float(level, n_80389070);
    load_int(self->ignore, n_8038907c);
    return self;
}


