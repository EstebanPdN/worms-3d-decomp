#include "w3d_ptr.h"
#line 1 "k4a_camera_mode_construct_800e7278.cpp"
struct K4aRefVtable;
struct K4aRef { Ptr32<const K4aRefVtable> vtable; };
struct K4aRefVtable { Ptr32<void (void)> unknown_00[3]; Ptr32<void (Ptr32<K4aRef>)> retain; Ptr32<void (Ptr32<K4aRef>)> release; };
struct K4aRefSlot {
    Ptr32<K4aRef> ref;
    int unused;
    template <class W3dU> K4aRefSlot(Ptr32<W3dU> w3d_p) : K4aRefSlot((K4aRef *)w3d_p.get()) {}
 K4aRefSlot(K4aRef *r) : ref(r) {}
    ~K4aRefSlot() { if (ref) ref->vtable->release(ref); }
};
struct K4aCameraMode { char pad0[72]; Ptr32<const void> vtable; int first; int second; Ptr32<K4aRef> input; };
extern "C" char w3d_str_8038afdc[];
extern "C" Ptr32<const void> w3d_vtable_80410138[];
extern "C" int w3d_constructor_lookup_name(Ptr32<Ptr32<const char>> name, Ptr32<K4aRefSlot> output);
extern "C" Ptr32<K4aRef> w3d_constructor_native_cast(Ptr32<K4aRef>);
extern "C" int FUN_8015a0d4(Ptr32<K4aCameraMode> self, int a, int b);

extern "C" Ptr32<K4aCameraMode> k4a_camera_mode_construct_800e7278(Ptr32<K4aCameraMode> self, int arg)
{
    int zero = 0;
    FUN_8015a0d4(self, arg, 14);
    self->vtable = w3d_vtable_80410138;
    self->input = (Ptr32<K4aRef>)w3d::G(zero);
    Ptr32<const char> name = w3d_str_8038afdc;
    K4aRefSlot slot((Ptr32<K4aRef>)w3d::G(zero));
    w3d_constructor_lookup_name(&name, &slot);
    Ptr32<K4aRef> ref = w3d_constructor_native_cast(slot.ref);
    if (ref != 0)
        ref->vtable->retain(ref);
    if (self->input != 0)
        self->input->vtable->release(self->input);
    self->input = ref;
    self->second = zero;
    self->first = zero;
    return self;
}


