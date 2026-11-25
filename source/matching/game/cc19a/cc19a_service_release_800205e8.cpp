// Layout is observed: retained interfaces at offsets48..112 and28.
struct Cc19aInterface {void **vtable;};
struct Cc19aService {void *vtable;char pad04[24];Cc19aInterface *held28;char pad32[16];Cc19aInterface *lists[17];};
extern "C" char lbl_8040db08[];
extern "C" int lbl_804b1760;
extern "C" void fn_800068b0(int);
extern "C" void fn_801628ec(Cc19aService*,int);
extern "C" void w3d_cc19a_service_release_800205e8(Cc19aService*self,int flags){
self->vtable=lbl_8040db08;
fn_800068b0(0);
lbl_804b1760=0;
if(self->lists[16]) ((void(*)(Cc19aInterface*))self->lists[16]->vtable[4])(self->lists[16]);
if(self->lists[15]) ((void(*)(Cc19aInterface*))self->lists[15]->vtable[4])(self->lists[15]);
if(self->lists[14]) ((void(*)(Cc19aInterface*))self->lists[14]->vtable[4])(self->lists[14]);
if(self->lists[13]) ((void(*)(Cc19aInterface*))self->lists[13]->vtable[4])(self->lists[13]);
if(self->lists[12]) ((void(*)(Cc19aInterface*))self->lists[12]->vtable[4])(self->lists[12]);
if(self->lists[11]) ((void(*)(Cc19aInterface*))self->lists[11]->vtable[4])(self->lists[11]);
if(self->lists[10]) ((void(*)(Cc19aInterface*))self->lists[10]->vtable[4])(self->lists[10]);
if(self->lists[9]) ((void(*)(Cc19aInterface*))self->lists[9]->vtable[4])(self->lists[9]);
if(self->lists[8]) ((void(*)(Cc19aInterface*))self->lists[8]->vtable[4])(self->lists[8]);
if(self->lists[7]) ((void(*)(Cc19aInterface*))self->lists[7]->vtable[4])(self->lists[7]);
if(self->lists[6]) ((void(*)(Cc19aInterface*))self->lists[6]->vtable[4])(self->lists[6]);
if(self->lists[5]) ((void(*)(Cc19aInterface*))self->lists[5]->vtable[4])(self->lists[5]);
if(self->lists[4]) ((void(*)(Cc19aInterface*))self->lists[4]->vtable[4])(self->lists[4]);
if(self->lists[3]) ((void(*)(Cc19aInterface*))self->lists[3]->vtable[4])(self->lists[3]);
if(self->lists[2]) ((void(*)(Cc19aInterface*))self->lists[2]->vtable[4])(self->lists[2]);
if(self->lists[1]) ((void(*)(Cc19aInterface*))self->lists[1]->vtable[4])(self->lists[1]);
if(self->lists[0]) ((void(*)(Cc19aInterface*))self->lists[0]->vtable[4])(self->lists[0]);
if(self->held28) ((void(*)(Cc19aInterface*))self->held28->vtable[4])(self->held28);
fn_801628ec(self,flags);}