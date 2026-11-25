#include "w3d_ptr.h"
#line 1 "k4a_object_count_refresh_80022d6c.cpp"
struct K4aRefVtable;
struct K4aRef { Ptr32<const K4aRefVtable> vtable; };
struct K4aRefVtable { Ptr32<void (void)> unknown_00[3]; Ptr32<void (Ptr32<K4aRef>)> retain; Ptr32<void (Ptr32<K4aRef>)> release; };
struct K4aRefSlot {
    Ptr32<K4aRef> ref;
    int unused;
    K4aRefSlot() : ref(0) {}
    ~K4aRefSlot() { if (ref) ref->vtable->release(ref); }
};
extern "C" char w3d_str_8036c53c[];
extern "C" Ptr32<K4aRef> w3d_held_804aca48;
extern "C" int w3d_constructor_lookup_name(Ptr32<Ptr32<const char>> name, Ptr32<K4aRefSlot> output);
extern "C" Ptr32<K4aRef> w3d_empty_803426b4(Ptr32<K4aRef>);
extern "C" int s9_update_value_80178c54(Ptr32<K4aRef> object, Ptr32<int> value);

extern "C" void k4a_object_count_refresh_80022d6c()
{
    {
        Ptr32<const char> name = w3d_str_8036c53c;
        K4aRefSlot slot;
        w3d_constructor_lookup_name(&name, &slot);
        Ptr32<K4aRef> ref = w3d_empty_803426b4(slot.ref);
        if (ref != 0)
            ref->vtable->retain(ref);
        if (w3d_held_804aca48 != 0)
            w3d_held_804aca48->vtable->release(w3d_held_804aca48);
        w3d_held_804aca48 = ref;
    }
    int value = 0;
    s9_update_value_80178c54(w3d_held_804aca48, &value);
}


