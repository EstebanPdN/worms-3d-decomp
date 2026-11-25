#include "w3d_ptr.h"
#line 1 "d25l_clear_selection_802b66c4.cpp"
// GWMP8P rev0 0x802b66c4. Releases the selection state of a mesh-picker
// view.
struct Obj;
struct ObjVt { Ptr32<void> s0[4]; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Held { Ptr32<Obj> value; template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 Held &operator=(Obj *p) { if (value) value->vt->release(value); value = p; return *this; } };
struct F1pRecordOwner { ~F1pRecordOwner();  char w3d_empty; };
extern "C" void w3d_auto_8015fd1c(Ptr32<void>);
extern "C" void w3d_s21_release_slots_802ba070(Ptr32<struct R>);
extern "C" void w3d_auto_802b0fec(Ptr32<void>);
extern int d25l_current_804abb4c;
struct R { char pad0[28]; char sub[184]; Held a212; Held a216; char pad220[64]; Ptr32<void> a284; Ptr32<void> a288; char pad292[112]; Ptr32<F1pRecordOwner> a404; int a408; };
extern "C" void d25l_clear_selection_802b66c4(Ptr32<R> self)
{
 self->a212 = 0;
 self->a216 = 0;
 if (self->a284) { w3d_auto_8015fd1c(self->a284); self->a284 = 0; }
 if (self->a408 == 1) { d25l_current_804abb4c = 0; self->a408 = 0; }
 if (self->a404) { delete self->a404; self->a404 = 0; }
 if (self->a288) { w3d_auto_8015fd1c(self->a288); self->a288 = 0; }

 w3d_s21_release_slots_802ba070(self);
 w3d_auto_802b0fec(self->sub);
}


