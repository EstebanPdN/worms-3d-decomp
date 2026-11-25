#include "w3d_ptr.h"
#line 1 "cc38b_activate_pending_8020ff44.cpp"
// Intrusive list and virtual service are observed partial views, inferred names.
struct Cc38bNode {Ptr32<void> vtable;Ptr32<Cc38bNode> next;unsigned unknown[6];unsigned flags;};
struct Cc38bService;
struct Cc38bServiceVtable {Ptr32<void> unknown[3];Ptr32<void (Ptr32<Cc38bService>)> retain;Ptr32<void> gap[6];Ptr32<void (Ptr32<Cc38bService>, Ptr32<Cc38bNode>)> attach;};
struct Cc38bService{Ptr32<Cc38bServiceVtable> vtable;};
extern "C" Ptr32<Cc38bNode> cc38b_pending_804b1900;
extern "C" Ptr32<Cc38bNode> cc38b_active_804b1908;
extern "C" Ptr32<Cc38bService> cc38b_service_804aba54;
extern "C" Ptr32<Cc38bService> cc38b_get_service_8020b648();
extern "C" int cc38b_eligible_801fff3c(Ptr32<Cc38bNode>);
extern "C" int cc38b_activate_pending_8020ff44(){
 if(cc38b_pending_804b1900){
 if(!cc38b_service_804aba54){
 cc38b_service_804aba54=cc38b_get_service_8020b648();
 cc38b_service_804aba54->vtable->retain(cc38b_service_804aba54);
 }
 Ptr32<Cc38bNode> head=cc38b_pending_804b1900;
 Ptr32<Cc38bNode> last=0;
 cc38b_pending_804b1900=last;
 for(Ptr32<Cc38bNode> p=head;p;p=p->next){
 if(cc38b_eligible_801fff3c(p))cc38b_service_804aba54->vtable->attach(cc38b_service_804aba54,p);
 p->flags|=0x100000;
 last=p;
 }
 if(last)last->next=cc38b_active_804b1908;
 cc38b_active_804b1908=head;
 }
 return 0;
}


