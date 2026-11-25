#include "w3d_ptr.h"
#line 1 "cc38b_remove_active_8020fe64.cpp"
// Intrusive list nodes and service vtable are partial, inferred views.
struct Cc38bNode{Ptr32<void> vtable;Ptr32<Cc38bNode> next;unsigned unknown[6];unsigned flags;};
struct Cc38bService;struct Cc38bVtable{Ptr32<void> unknown[11];Ptr32<void (Ptr32<Cc38bService>, Ptr32<Cc38bNode>)> remove;};
struct Cc38bService{Ptr32<Cc38bVtable> vtable;};
extern "C" int cc38b_eligible_801fff3c(Ptr32<Cc38bNode>);
extern "C" int cc38b_enabled_8020b458();
extern "C" Ptr32<Cc38bService> cc38b_service_8020b648();
extern "C" Ptr32<Cc38bNode> cc38b_special_804b1904;
extern "C" Ptr32<Cc38bNode> cc38b_normal_804b1908;
extern "C" void cc38b_remove_active_8020fe64(Ptr32<Cc38bNode> self){
 if(cc38b_eligible_801fff3c(self)&&cc38b_enabled_8020b458()){
 Ptr32<Cc38bService> s=cc38b_service_8020b648();s->vtable->remove(s,self);
 }
 Ptr32<Cc38bNode> last=0;
 Ptr32<Cc38bNode> p=(self->flags&0x200000)?w3d::R(cc38b_special_804b1904):w3d::R(cc38b_normal_804b1908);
 for(;p;last=p,p=p->next){
 if(p==self){
 if(last)last->next=self->next;
 else if(self->flags&0x200000)cc38b_special_804b1904=self->next;
 else cc38b_normal_804b1908=self->next;
 break;
 }
 }
 self->next=0;
}


