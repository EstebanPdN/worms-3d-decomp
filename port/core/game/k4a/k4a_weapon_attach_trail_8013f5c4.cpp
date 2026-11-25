#include "w3d_ptr.h"
#line 1 "k4a_weapon_attach_trail_8013f5c4.cpp"
struct K4aRefVtable;
struct K4aRef { Ptr32<const K4aRefVtable> vtable; };
struct K4aRefVtable { Ptr32<void (void)> unknown_00[3]; Ptr32<void (Ptr32<K4aRef>)> retain; Ptr32<void (Ptr32<K4aRef>)> release; };
struct K4aHeld {
    Ptr32<K4aRef> ref;
    int unused;
    template <class W3dU> K4aHeld(Ptr32<W3dU> w3d_p) : K4aHeld((K4aRef *)w3d_p.get()) {}
 K4aHeld(K4aRef *r) : ref(r) { if (ref) ref->vtable->retain(ref); }
    ~K4aHeld() { if (ref) ref->vtable->release(ref); }
};
struct K4aString { Ptr32<char> text; };
struct K4aAttach;
struct K4aAttachVtable { Ptr32<void (void)> unknown_00[23]; Ptr32<int (Ptr32<K4aAttach>, int, Ptr32<const char>)> attach; };
struct K4aAttach { Ptr32<const K4aAttachVtable> vtable; };
struct K4aWeapon { char pad0[20]; unsigned int owner; char pad1[8]; int first_node; int second_node; char pad2[116]; Ptr32<void> trail; char pad3[4]; Ptr32<K4aAttach> attach; };
extern "C" char w3d_service_80410b08[];
extern "C" char w3d_str_8039fdcc[];
extern "C" char w3d_str_8039fddc[];
extern "C" char w3d_str_8039fde4[];
extern "C" Ptr32<void> w3d_context_804b178c;
extern "C" Ptr32<K4aRef> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" Ptr32<void> FUN_80164514(Ptr32<void> context, Ptr32<K4aRef> ref, unsigned int owner);
extern "C" void FUN_8013f6b4(Ptr32<K4aWeapon> self);
extern "C" Ptr32<void> w3d_string_from_text(Ptr32<K4aString> string, Ptr32<const char> text);
extern "C" int FUN_801222cc(Ptr32<K4aRef> ref, Ptr32<K4aString> name, int a, int b, int c);

extern "C" void k4a_weapon_attach_trail_8013f5c4(Ptr32<K4aWeapon> self)
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


