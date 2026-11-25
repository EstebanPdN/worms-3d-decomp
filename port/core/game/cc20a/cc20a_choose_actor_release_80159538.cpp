#include "w3d_ptr.h"
#line 1 "cc20a_choose_actor_release_80159538.cpp"
// Nine retained interface members follow the actor base's 28-byte extent.
struct Cc20aInterface {Ptr32<Ptr32<void>> vtable;};
struct Cc20aChooseActor {Ptr32<void> vtable;char reserved[24];Ptr32<Cc20aInterface> held[9];};
extern "C" char lbl_80410f80[],lbl_803a3fd0[];
extern "C" int lbl_804ab40c;
extern "C" int fn_800fc43c(Ptr32<Ptr32<const char>>,int);
extern "C" void fn_80161050(Ptr32<Cc20aChooseActor>,int);
extern "C" void w3d_cc20a_choose_actor_release_80159538(Ptr32<Cc20aChooseActor> self,int flags){
self->vtable=lbl_80410f80;lbl_804ab40c=0;
Ptr32<const char> key=lbl_803a3fd0;fn_800fc43c(&key,0);
if(self->held[8]) ((Ptr32<void (Ptr32<Cc20aInterface>)>)self->held[8]->vtable[4])(self->held[8]);
if(self->held[7]) ((Ptr32<void (Ptr32<Cc20aInterface>)>)self->held[7]->vtable[4])(self->held[7]);
if(self->held[6]) ((Ptr32<void (Ptr32<Cc20aInterface>)>)self->held[6]->vtable[4])(self->held[6]);
if(self->held[5]) ((Ptr32<void (Ptr32<Cc20aInterface>)>)self->held[5]->vtable[4])(self->held[5]);
if(self->held[4]) ((Ptr32<void (Ptr32<Cc20aInterface>)>)self->held[4]->vtable[4])(self->held[4]);
if(self->held[3]) ((Ptr32<void (Ptr32<Cc20aInterface>)>)self->held[3]->vtable[4])(self->held[3]);
if(self->held[2]) ((Ptr32<void (Ptr32<Cc20aInterface>)>)self->held[2]->vtable[4])(self->held[2]);
if(self->held[1]) ((Ptr32<void (Ptr32<Cc20aInterface>)>)self->held[1]->vtable[4])(self->held[1]);
if(self->held[0]) ((Ptr32<void (Ptr32<Cc20aInterface>)>)self->held[0]->vtable[4])(self->held[0]);
fn_80161050(self,flags);}

