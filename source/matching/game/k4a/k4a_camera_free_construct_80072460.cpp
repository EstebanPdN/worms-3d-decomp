struct K4aRefVtable;
struct K4aRef { const K4aRefVtable *vtable; };
struct K4aRefVtable { void (*unknown_00[3])(void); void (*retain)(K4aRef *self); void (*release)(K4aRef *self); };
struct K4aRefSlot {
    K4aRef *ref;
    int unused;
    K4aRefSlot(K4aRef *r) : ref(r) {}
    ~K4aRefSlot() { if (ref) ref->vtable->release(ref); }
};
struct K4aCameraMode { char pad0[72]; const void *vtable; char pad1[8]; float first; float second; K4aRef *input; };
extern "C" char w3d_str_8037ccac[];
extern "C" const float w3d_f32_8037ccc4[];
extern "C" const void *w3d_vtable_8040f0a8[];
extern "C" int w3d_constructor_lookup_name(const char **name, K4aRefSlot *output);
extern "C" K4aRef *w3d_constructor_native_cast(K4aRef *);
extern "C" int FUN_8015a0d4(K4aCameraMode *self, int a, int b);

extern "C" K4aCameraMode *k4a_camera_free_construct_80072460(K4aCameraMode *self, int arg)
{
    FUN_8015a0d4(self, arg, 16);
    self->vtable = w3d_vtable_8040f0a8;
    self->input = 0;
    K4aRefSlot slot(0);
    const char *name = w3d_str_8037ccac;
    w3d_constructor_lookup_name(&name, &slot);
    K4aRef *ref = w3d_constructor_native_cast(slot.ref);
    if (ref != 0)
        ref->vtable->retain(ref);
    if (self->input != 0)
        self->input->vtable->release(self->input);
    self->input = ref;
    self->first = w3d_f32_8037ccc4[0];
    self->second = w3d_f32_8037ccc4[0];
    return self;
}
