struct K4aRefVtable;
struct K4aRef { const K4aRefVtable *vtable; };
struct K4aRefVtable { void (*unknown_00[3])(void); void (*retain)(K4aRef *self); void (*release)(K4aRef *self); };
struct K4aHeld {
    K4aRef *ref;
    int unused;
    K4aHeld(K4aRef *r) : ref(r) { if (ref) ref->vtable->retain(ref); }
    ~K4aHeld() { if (ref) ref->vtable->release(ref); }
};
struct K4aString { char *text; };
struct K4aAttach;
struct K4aAttachVtable { void (*unknown_00[23])(void); int (*attach)(K4aAttach *self, int node, const char *name); };
struct K4aAttach { const K4aAttachVtable *vtable; };
struct K4aWeapon { char pad0[20]; unsigned int owner; char pad1[8]; int first_node; int second_node; char pad2[116]; void *trail; char pad3[4]; K4aAttach *attach; };
extern "C" char w3d_service_80410b08[];
extern "C" char w3d_str_8039fdcc[];
extern "C" char w3d_str_8039fddc[];
extern "C" char w3d_str_8039fde4[];
extern "C" void *w3d_context_804b178c;
extern "C" K4aRef *w3d_s10_service_forward_8020b680(void *);
extern "C" void *FUN_80164514(void *context, K4aRef *ref, unsigned int owner);
extern "C" void FUN_8013f6b4(K4aWeapon *self);
extern "C" void * w3d_string_from_text(K4aString *string, const char *text);
extern "C" int FUN_801222cc(K4aRef *ref, K4aString *name, int a, int b, int c);

extern "C" void k4a_weapon_attach_trail_8013f5c4(K4aWeapon *self)
{
    FUN_8013f6b4(self);
    K4aHeld held(w3d_s10_service_forward_8020b680(w3d_service_80410b08));
    self->trail = FUN_80164514(w3d_context_804b178c, held.ref, self->owner);
    K4aString name;
    w3d_string_from_text(&name, w3d_str_8039fdcc);
    FUN_801222cc(held.ref, &name, 20, 0, 1);
    self->attach->vtable->attach(self->attach, self->first_node, w3d_str_8039fddc);
    self->attach->vtable->attach(self->attach, self->second_node, w3d_str_8039fde4);
}
