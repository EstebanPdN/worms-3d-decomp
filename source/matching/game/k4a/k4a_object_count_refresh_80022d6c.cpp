struct K4aRefVtable;
struct K4aRef { const K4aRefVtable *vtable; };
struct K4aRefVtable { void (*unknown_00[3])(void); void (*retain)(K4aRef *self); void (*release)(K4aRef *self); };
struct K4aRefSlot {
    K4aRef *ref;
    int unused;
    K4aRefSlot() : ref(0) {}
    ~K4aRefSlot() { if (ref) ref->vtable->release(ref); }
};
extern "C" char w3d_str_8036c53c[];
extern "C" K4aRef *w3d_held_804aca48;
extern "C" int w3d_constructor_lookup_name(const char **name, K4aRefSlot *output);
extern "C" K4aRef *w3d_empty_803426b4(K4aRef *);
extern "C" int s9_update_value_80178c54(K4aRef *object, int *value);

extern "C" void k4a_object_count_refresh_80022d6c()
{
    {
        const char *name = w3d_str_8036c53c;
        K4aRefSlot slot;
        w3d_constructor_lookup_name(&name, &slot);
        K4aRef *ref = w3d_empty_803426b4(slot.ref);
        if (ref != 0)
            ref->vtable->retain(ref);
        if (w3d_held_804aca48 != 0)
            w3d_held_804aca48->vtable->release(w3d_held_804aca48);
        w3d_held_804aca48 = ref;
    }
    int value = 0;
    s9_update_value_80178c54(w3d_held_804aca48, &value);
}
