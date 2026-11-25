#include "w3d_ptr.h"
#line 1 "d24i_hud_3d_construct_8011a918.cpp"
// d24i: 0x8011a918 (384 bytes). Constructor of a 3D HUD element: base
// constructor 0x8015fef0, vtable 0x80410a20, clears the references at +28, +32,
// +48, +76 and +80, sets the vector +52 to the constant 0x8039ae80, copies the
// small-data default pair 0x804af3b0 to +68, resolves the two HUD.3D
// settings named at 0x8039ae48 and 0x8039ae64 into retained references +76 and
// +80, and sets +64 to 1.
struct d24i_Object;
struct d24i_ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<d24i_Object>)> retain;       // +12
    Ptr32<void (Ptr32<d24i_Object>)> release;      // +16
};
struct d24i_Object { Ptr32<d24i_ObjectVtable> vtable; };
struct d24i_Key { Ptr32<const char> name; };
struct d24i_Ref;
extern "C" int d24i_setting_lookup_800fc1b0(Ptr32<d24i_Key>, Ptr32<d24i_Ref>);
struct d24i_Ref {
 d24i_Ref(const d24i_Ref &);
    Ptr32<d24i_Object> value;
    // One word with a user copy constructor: the keys follow this object at
    // +16 and +20 in the original (object +8), while each key occupies 4.
    template <class W3dU> d24i_Ref(Ptr32<W3dU> w3d_p) : d24i_Ref((const char *)w3d_p.get()) {}
 d24i_Ref(const char *name) {
        d24i_Key key;
        key.name = name;
        value = 0;
        d24i_setting_lookup_800fc1b0(&key, this);
    }
    ~d24i_Ref() { if (value) value->vtable->release(value); }
};
struct d24i_Range { int low, high; };
struct d24i_Hud3d {
    Ptr32<const void> vtable;
    unsigned char unknown04[24];
    Ptr32<d24i_Object> ref1c;                  // +28
    Ptr32<d24i_Object> ref20;                  // +32
    unsigned char unknown24[12];
    int unknown30;                       // +48
    float position[3];                   // +52
    int active;                          // +64
    d24i_Range range;                    // +68
    Ptr32<d24i_Object> first;                  // +76
    Ptr32<d24i_Object> second;                 // +80
};
extern "C" int d24i_base_construct_8015fef0(Ptr32<d24i_Hud3d>);
extern "C" Ptr32<d24i_Object> d24i_as_object_80342a74(Ptr32<d24i_Object>);
extern Ptr32<const void> const d24i_vtable_80410a20[];
extern const char d24i_name_8039ae48[], d24i_name_8039ae64[];
extern const float d24i_zero_8039ae80[];
extern d24i_Range d24i_default_804af3b0;
static inline void d24i_assign(Ptr32<d24i_Object> &slot, Ptr32<d24i_Object> value) {
    if (value) value->vtable->retain(value);
    if (slot) slot->vtable->release(slot);
    slot = value;
}

extern "C" Ptr32<d24i_Hud3d> d24i_hud_3d_construct_8011a918(Ptr32<d24i_Hud3d> self) {
    d24i_base_construct_8015fef0(self);
    self->vtable = d24i_vtable_80410a20;
    self->ref1c = 0;
    self->ref20 = 0;
    self->unknown30 = 0;
    self->first = 0;
    self->second = 0;
    float zero = d24i_zero_8039ae80[0];
    self->position[0] = zero;
    Ptr32<float> position = self->position;
    position[1] = zero;
    position[2] = zero;
    self->range.low = d24i_default_804af3b0.low;
    self->range.high = d24i_default_804af3b0.high;
    {
        d24i_Ref found(d24i_name_8039ae48);
        d24i_assign(self->first, d24i_as_object_80342a74(found.value));
    }
    {
        d24i_Ref found(d24i_name_8039ae64);
        d24i_assign(self->second, d24i_as_object_80342a74(found.value));
    }
    self->active = 1;
    return self;
}


