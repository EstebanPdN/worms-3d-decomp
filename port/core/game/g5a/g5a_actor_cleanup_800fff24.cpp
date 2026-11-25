#include "w3d_ptr.h"
#line 1 "g5a_actor_cleanup_800fff24.cpp"
// External receiver and external pointee views; no local instances.
extern "C" void free_802134fc(Ptr32<void>),finish_8020c5c4(Ptr32<void>),string_80341588(Ptr32<void>),member_8015f558(Ptr32<void>,int),node_8020803c(Ptr32<void>,int),scalar_801fe1f8(Ptr32<void>),pool_80209920(Ptr32<void>,Ptr32<void>),clear_80102474(Ptr32<void>),base_801628ec(Ptr32<void>,int);
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned,...);
extern unsigned pool_804af15c;extern Ptr32<void> vtable_804105f8[];
struct G5aActorIface{Ptr32<Ptr32<void>> vtable;};
struct G5aActorHeld{Ptr32<G5aActorIface> p;~G5aActorHeld(){if(p)((Ptr32<void (Ptr32<G5aActorIface>)>)p->vtable[4])(p);}void reset(Ptr32<G5aActorIface> q){if(p)((Ptr32<void (Ptr32<G5aActorIface>)>)p->vtable[4])(p);p=q;}};
struct G5aActorString{Ptr32<void> p;~G5aActorString(){finish_8020c5c4(this);string_80341588(this);}};
struct G5aActorMember{unsigned unknown[2];~G5aActorMember();};
struct G5aActorNode{unsigned unknown[7];~G5aActorNode();};
struct G5aActorTextCache:G5aActorMember {G5aActorString text __attribute__((aligned(__alignof__(G5aActorMember))));};
struct G5aActorRecord{
 static void operator delete(void*p){pool_80209920(&pool_804af15c,p);}
 Ptr32<Ptr32<void>> vtable;G5aActorString name;unsigned unknown8;G5aActorHeld held;G5aActorTextCache cache;unsigned live;
};
struct G5aActorBox{
 static void operator delete(void*p){scalar_801fe1f8(p);}
 G5aActorHeld held;
};
struct G5aActorStorage{Ptr32<void> begin;~G5aActorStorage(){if(begin)free_802134fc(begin);}};
template<class T>struct G5aActorRange{
 Ptr32<Ptr32<T>> begin; Ptr32<Ptr32<T>> end;unsigned capacity;
 ~G5aActorRange(){if(begin)free_802134fc(begin);}
 Ptr32<T> get(unsigned i){return *(Ptr32<Ptr32<T>>)((Ptr32<char>)begin+(i<<2));}
 unsigned size(){return end-begin;}
 void clear(){int bytes=(Ptr32<char>)end-(Ptr32<char>)begin;copy_802eee50(begin,end,0);end=(Ptr32<Ptr32<T>>)((Ptr32<char>)end-bytes);}
};
struct G5aActorOwner{
 Ptr32<Ptr32<void>> vtable;char unknown4[24];G5aActorStorage storage;char unknown32[12];
 G5aActorHeld held44,held48,held52,held56,held60,held64;int resetHeld;char unknown72[260];
 G5aActorNode node;G5aActorString a,b;unsigned unknown368;G5aActorRange<G5aActorBox> boxes;G5aActorRange<G5aActorRecord> records;
 ~G5aActorOwner(){
  vtable=vtable_804105f8;
  if(resetHeld){held64.reset(0);held60.reset(0);}
  clear_80102474(this);
  for(unsigned i=0;i<records.size();++i)delete records.get(i);
  records.clear();
  for(unsigned i=0;i<boxes.size();++i)delete boxes.get(i);
  boxes.clear();
 }
};
extern "C" void g5a_actor_cleanup_800fff24(Ptr32<G5aActorOwner> self,int flags){self->~G5aActorOwner();base_801628ec(self,flags);}


