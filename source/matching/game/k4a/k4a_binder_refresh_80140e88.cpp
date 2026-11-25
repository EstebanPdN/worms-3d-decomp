struct K4aRefVtable;
struct K4aRef { const K4aRefVtable *vtable; };
struct K4aRefVtable { void (*unknown_00[3])(void); void (*retain)(K4aRef *self); void (*release)(K4aRef *self); };
struct K4aRefSlot {
    K4aRef *ref;
    int unused;
    K4aRefSlot() : ref(0) {}
    ~K4aRefSlot() { if (ref) ref->vtable->release(ref); }
};
struct K4aBinder { char pad0[20]; unsigned int owner; char pad1[4]; void *first; void *second; char pad2[12]; K4aRef *held; };
extern "C" char w3d_service_80410a10[];
extern "C" char w3d_str_803a0430[];
extern "C" K4aRef *w3d_s10_service_forward_8020b680(void *);
extern "C" void *FUN_80164514(void *context, K4aRef *ref, unsigned int owner);
extern "C" void *w3d_context_804b178c;
extern "C" int w3d_constructor_lookup_name(const char **name, K4aRefSlot *output);
extern "C" K4aRef *w3d_empty_80341584(K4aRef *);

extern "C" void k4a_binder_refresh_80140e88(K4aBinder *self)
{
    void *type = w3d_service_80410a10;
    K4aRef *service = w3d_s10_service_forward_8020b680(type);
    self->first = FUN_80164514(w3d_context_804b178c, service, self->owner);
    service = w3d_s10_service_forward_8020b680(type);
    self->second = FUN_80164514(w3d_context_804b178c, service, self->owner);
    const char *name = w3d_str_803a0430;
    K4aRefSlot slot;
    w3d_constructor_lookup_name(&name, &slot);
    K4aRef *ref = w3d_empty_80341584(slot.ref);
    if (ref != 0)
        ref->vtable->retain(ref);
    if (self->held != 0)
        self->held->vtable->release(self->held);
    self->held = ref;
}
