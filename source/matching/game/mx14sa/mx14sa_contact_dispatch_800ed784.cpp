// External GC32 partial view. Position/velocity names and contact semantics are inferred.
struct Mx14saContactVector { float x,y,z; };
struct Mx14saContactObject {
 void **vtable;
 unsigned observed_words[8];
 Mx14saContactVector position,velocity;
};
extern "C" int query_800ea748(Mx14saContactObject *,Mx14saContactVector *,Mx14saContactVector *,Mx14saContactVector *,Mx14saContactVector *,unsigned *,long long *);
extern "C" void fallback_800eaf14(Mx14saContactObject *);
extern "C" void mx14sa_contact_dispatch_800ed784(Mx14saContactObject *self) {
 Mx14saContactVector first,second;
 unsigned kind;
 long long time;
 Mx14saContactVector *normal=&second;
 Mx14saContactVector *position=&self->position;
 Mx14saContactVector *velocity=&self->velocity;
 if(query_800ea748(self,position,velocity,&first,normal,&kind,&time)) {
  ((void (*)(Mx14saContactObject *,long long,Mx14saContactVector *,Mx14saContactVector *,Mx14saContactVector *))self->vtable[21])(self,time,normal,velocity,&first);
 } else if(((int (*)(Mx14saContactObject *,Mx14saContactVector *,Mx14saContactVector *,Mx14saContactVector *,Mx14saContactVector *))self->vtable[16])(self,position,velocity,&first,normal)) {
  ((void (*)(Mx14saContactObject *,long long,Mx14saContactVector *,Mx14saContactVector *,Mx14saContactVector *))self->vtable[21])(self,0x40000000LL,normal,velocity,&first);
 } else fallback_800eaf14(self);
}
