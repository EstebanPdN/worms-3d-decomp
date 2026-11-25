// Scheme data tag (Worms 3D GameCube PAL, 0x8021deec).
// 
// Reads the GM.SchemeData property into a released handle, casts it through the
// type descriptor (released via 0x80178474; both of its words are written),
// retains the result and propagates the owner's tag at +28 to it (0x801ea4c8).
// Same reference layout as d24b_inventory_tick_8008a8b4.

struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);
    void (*release)(Object *);
};
struct Object { ObjectVtable *vtable; };
struct Descriptor_80178474 {
    void *value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Held {
    Held(const Held &);
    Object *value;
    Held() : value(0) {}
    Held(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    ~Held() { if (value) value->vtable->release(value); }
    void assign(Object *next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct Handle {
    Object *value;
    ~Handle() { if (value) value->vtable->release(value); }
    Handle(const Handle &);
    Handle() {}
};
struct PropertyKey { const char *name; };
struct Scheme { char pad[28]; int tag; };
extern "C" int property_800fc1b0(PropertyKey *, Object **);
extern "C" void *identity_80341584(Object *);
extern "C" Object *as_type_80179598(void *, Descriptor_80178474 *);
extern "C" void propagate_801ea4c8(Object *, void *);
extern const char text_803b46f8[];
extern "C" void w3d_d26k_scheme_tag_8021deec(Scheme *self) {
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
    propagate_801ea4c8(current.value, (void *)self->tag);
}
