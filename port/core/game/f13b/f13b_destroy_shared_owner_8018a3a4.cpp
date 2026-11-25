#include "w3d_ptr.h"
#line 1 "f13b_destroy_shared_owner_8018a3a4.cpp"
// Names and partial type views are inferred. No local object construction or allocation.
extern "C" void fn_801fe240(Ptr32<void>);extern "C" void fn_80190384(Ptr32<void>,int);
extern Ptr32<void> vt_80412ee0[];extern int lbl_804b18a8;
struct F13bOwnerIface{Ptr32<Ptr32<void>> table;};
struct F13bOwnerHeld{Ptr32<F13bOwnerIface> p;inline void reset(Ptr32<F13bOwnerIface> next){if(p)((Ptr32<void (Ptr32<F13bOwnerIface>)>)p->table[4])(p);p=next;}inline void release(){if(p)((Ptr32<void (Ptr32<F13bOwnerIface>)>)p->table[4])(p);}};
struct F13bOwnerView{Ptr32<Ptr32<void>> table;char unknown4[28];F13bOwnerHeld first,second,third;char unknown44[24];Ptr32<void> buffer;};
extern F13bOwnerHeld lbl_804b0238;
extern F13bOwnerHeld lbl_804b023c;
extern F13bOwnerHeld lbl_804b0240;
extern F13bOwnerHeld lbl_804b0244;
extern F13bOwnerHeld lbl_804b0248;
extern F13bOwnerHeld lbl_804b024c;
extern F13bOwnerHeld lbl_804b0250;
extern F13bOwnerHeld lbl_804b0254;
extern F13bOwnerHeld lbl_804b0258;
extern F13bOwnerHeld lbl_804b025c;
extern F13bOwnerHeld lbl_804b0264;
extern F13bOwnerHeld lbl_804b0268;
extern F13bOwnerHeld lbl_804b026c;
extern F13bOwnerHeld lbl_804b0260;
extern "C" void f13b_destroy_8018a3a4(Ptr32<F13bOwnerView> self,int flags){self->table=vt_80412ee0;self->first.reset(0);self->second.reset(0);if(--lbl_804b18a8==0){
lbl_804b0238.reset(0);
lbl_804b023c.reset(0);
lbl_804b0240.reset(0);
lbl_804b0244.reset(0);
lbl_804b0248.reset(0);
lbl_804b024c.reset(0);
lbl_804b0250.reset(0);
lbl_804b0254.reset(0);
lbl_804b0258.reset(0);
lbl_804b025c.reset(0);
lbl_804b0264.reset(0);
lbl_804b0268.reset(0);
lbl_804b026c.reset(0);
lbl_804b0260.reset(0);
}if(self->buffer)fn_801fe240(self->buffer);self->third.release();self->second.release();self->first.release();fn_80190384(self,flags);}


