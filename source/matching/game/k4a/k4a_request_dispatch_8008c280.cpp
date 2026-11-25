struct K4aRefVtable;
struct K4aRef { const K4aRefVtable *vtable; };
struct K4aRefVtable { void (*unknown_00[3])(void); void (*retain)(K4aRef *self); void (*release)(K4aRef *self); };
struct K4aHeld {
    K4aRef *ref;
    K4aHeld(K4aRef *r) : ref(r) { if (ref) ref->vtable->retain(ref); }
    ~K4aHeld() { if (ref) ref->vtable->release(ref); }
};
struct K4aRequest { char pad0[20]; unsigned int value; };
extern "C" char w3d_service_8040e708[];
extern "C" K4aRef *w3d_s10_service_forward_8020b680(void *);
extern "C" int FUN_80164514(void *context, K4aRef *ref, unsigned int value);
extern "C" void *w3d_context_804b178c;

extern "C" void k4a_request_dispatch_8008c280(K4aRequest *self)
{
    K4aHeld held(w3d_s10_service_forward_8020b680(w3d_service_8040e708));
    FUN_80164514(w3d_context_804b178c, held.ref, self->value);
}
