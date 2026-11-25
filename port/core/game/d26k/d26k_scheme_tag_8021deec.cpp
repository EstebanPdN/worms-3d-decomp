#include "w3d_ptr.h"
#line 1 "d26k_scheme_tag_8021deec.cpp"
// Scheme data tag (Worms 3D GameCube PAL, 0x8021deec).
// 
// Reads the GM.SchemeData property into a released handle, casts it through the
// type descriptor (released via 0x80178474; both of its words are written),
// retains the result and propagates the owner's tag at +28 to it (0x801ea4c8).
// Same reference layout as d24b_inventory_tick_8008a8b4.

struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;
    Ptr32<void (Ptr32<Object>)> release;
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Held {
    Held(const Held &);
    Ptr32<Object> value;
    Held() : value(0) {}
    template <class W3dU> Held(Ptr32<W3dU> w3d_p) : Held((Object *)w3d_p.get()) {}
 Held(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    ~Held() { if (value) value->vtable->release(value); }
    void assign(Ptr32<Object> next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct Handle {
    Ptr32<Object> value;
    ~Handle() { if (value) value->vtable->release(value); }
    Handle(const Handle &);
    Handle() {}
};
struct PropertyKey { Ptr32<const char> name; };
struct Scheme { char pad[28]; int tag; };
extern "C" int property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<void> identity_80341584(Ptr32<Object>);
extern "C" Ptr32<Object> as_type_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
extern "C" void propagate_801ea4c8(Ptr32<Object>, Ptr32<void>);
extern const char text_803b46f8[];
extern "C" void w3d_d26k_scheme_tag_8021deec(Ptr32<Scheme> self) {
    Descriptor_80178474 descriptor;
    Handle handle;
    handle.value = 0;
    {
        PropertyKey key;
        key.name = text_803b46f8;
        property_800fc1b0(&key, &handle.value);
    }
    Held current;
    {
        Held acquired(as_type_80179598(identity_80341584(handle.value), &descriptor));
        current.assign(acquired.value);
    }
    propagate_801ea4c8(current.value, (Ptr32<void>)w3d::G(self->tag));
}


