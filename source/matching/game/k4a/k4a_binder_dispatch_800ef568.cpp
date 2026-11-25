struct K4aRefVtable;
struct K4aRef { const K4aRefVtable *vtable; };
struct K4aRefVtable { void (*unknown_00[3])(void); void (*retain)(K4aRef *self); void (*release)(K4aRef *self); };
struct K4aHeld {
    K4aRef *ref;
    int unused;
    K4aHeld(K4aRef *r) : ref(r) { if (ref) ref->vtable->retain(ref); }
    ~K4aHeld() { if (ref) ref->vtable->release(ref); }
};
struct K4aSettings { char pad0[20]; unsigned int value; };
struct K4aBinder { char pad0[28]; K4aRef *ref; };
extern "C" char w3d_service_8040e4a8[];
extern "C" K4aRef *w3d_s10_service_forward_8020b680(void *);
extern "C" int w3d_assign_interface_arg_8002f6dc(K4aRef *target, K4aRef **source);
extern "C" int FUN_80164514(void *context, K4aRef *ref, unsigned int value);
extern "C" void *w3d_context_804b178c;
extern "C" K4aSettings *w3d_settings_804aab4c;

extern "C" void k4a_binder_dispatch_800ef568(K4aBinder *self)
{
    K4aHeld held(w3d_s10_service_forward_8020b680(w3d_service_8040e4a8));
    K4aRef *source = self->ref;
    if (source != 0)
        source->vtable->retain(source);
    w3d_assign_interface_arg_8002f6dc(held.ref, &source);
    FUN_80164514(w3d_context_804b178c, held.ref, w3d_settings_804aab4c->value);
}
