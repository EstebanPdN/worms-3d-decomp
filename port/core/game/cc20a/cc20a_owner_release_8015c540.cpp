#include "w3d_ptr.h"
#line 1 "cc20a_owner_release_8015c540.cpp"
// Observed interface pointers at 96,100,104,108,112; names are structural.
struct Cc20aInterface {Ptr32<Ptr32<void>> vtable;};
struct Cc20aOwner {Ptr32<void> vtable;char reserved[92];Ptr32<Cc20aInterface> held96; Ptr32<Cc20aInterface> held100; Ptr32<Cc20aInterface> held104; Ptr32<Cc20aInterface> held108; Ptr32<Cc20aInterface> held112;};
extern "C" char lbl_804111c8[];
extern "C" void fn_8015b630(Ptr32<Cc20aOwner>,int);
static inline void cc20a_release(Ptr32<Cc20aInterface> p){if(p)((Ptr32<void (Ptr32<Cc20aInterface>)>)p->vtable[4])(p);}
static inline void cc20a_reset(Ptr32<Cc20aInterface> &p,Ptr32<Cc20aInterface> value){cc20a_release(p);p=value;}
extern "C" void w3d_cc20a_owner_release_8015c540(Ptr32<Cc20aOwner> self){
 self->vtable=lbl_804111c8;
 cc20a_reset(self->held96,0);cc20a_reset(self->held108,0);cc20a_reset(self->held100,0);
 cc20a_release(self->held112);cc20a_release(self->held108);cc20a_release(self->held104);cc20a_release(self->held100);cc20a_release(self->held96);
 fn_8015b630(self,0);
}

