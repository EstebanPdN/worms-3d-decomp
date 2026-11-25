// Intrusive list and virtual service are observed partial views, inferred names.
struct Cc38bNode {void*vtable;Cc38bNode*next;unsigned unknown[6];unsigned flags;};
struct Cc38bService;
struct Cc38bServiceVtable {void*unknown[3];void(*retain)(Cc38bService*);void*gap[6];void(*attach)(Cc38bService*,Cc38bNode*);};
struct Cc38bService{Cc38bServiceVtable*vtable;};
extern "C" Cc38bNode*cc38b_pending_804b1900;
extern "C" Cc38bNode*cc38b_active_804b1908;
extern "C" Cc38bService*cc38b_service_804aba54;
extern "C" Cc38bService*cc38b_get_service_8020b648();
extern "C" int cc38b_eligible_801fff3c(Cc38bNode*);
extern "C" int cc38b_activate_pending_8020ff44(){
 if(cc38b_pending_804b1900){
 if(!cc38b_service_804aba54){
 cc38b_service_804aba54=cc38b_get_service_8020b648();
 cc38b_service_804aba54->vtable->retain(cc38b_service_804aba54);
 }
 Cc38bNode*head=cc38b_pending_804b1900;
 Cc38bNode*last=0;
 cc38b_pending_804b1900=last;
 for(Cc38bNode*p=head;p;p=p->next){
 if(cc38b_eligible_801fff3c(p))cc38b_service_804aba54->vtable->attach(cc38b_service_804aba54,p);
 p->flags|=0x100000;
 last=p;
 }
 if(last)last->next=cc38b_active_804b1908;
 cc38b_active_804b1908=head;
 }
 return 0;
}
