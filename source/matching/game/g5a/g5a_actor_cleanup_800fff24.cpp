// External receiver and external pointee views; no local instances.
extern "C" void free_802134fc(void*),finish_8020c5c4(void*),string_80341588(void*),member_8015f558(void*,int),node_8020803c(void*,int),scalar_801fe1f8(void*),pool_80209920(void*,void*),clear_80102474(void*),base_801628ec(void*,int);
extern "C" void *copy_802eee50(void*,const void*,unsigned,...);
extern unsigned pool_804af15c;extern void *vtable_804105f8[];
struct G5aActorIface{void **vtable;};
struct G5aActorHeld{G5aActorIface*p;~G5aActorHeld(){if(p)((void(*)(G5aActorIface*))p->vtable[4])(p);}void reset(G5aActorIface*q){if(p)((void(*)(G5aActorIface*))p->vtable[4])(p);p=q;}};
struct G5aActorString{void *p;~G5aActorString(){finish_8020c5c4(this);string_80341588(this);}};
struct G5aActorMember{unsigned unknown[2];~G5aActorMember();};
struct G5aActorNode{unsigned unknown[7];~G5aActorNode();};
struct G5aActorTextCache:G5aActorMember {G5aActorString text;};
struct G5aActorRecord{
 static void operator delete(void*p){pool_80209920(&pool_804af15c,p);}
 void **vtable;G5aActorString name;unsigned unknown8;G5aActorHeld held;G5aActorTextCache cache;unsigned live;
};
struct G5aActorBox{
 static void operator delete(void*p){scalar_801fe1f8(p);}
 G5aActorHeld held;
};
struct G5aActorStorage{void *begin;~G5aActorStorage(){if(begin)free_802134fc(begin);}};
template<class T>struct G5aActorRange{
 T **begin,**end;unsigned capacity;
 ~G5aActorRange(){if(begin)free_802134fc(begin);}
 T *get(unsigned i){return *(T**)((char*)begin+(i<<2));}
 unsigned size(){return end-begin;}
 void clear(){int bytes=(char*)end-(char*)begin;copy_802eee50(begin,end,0);end=(T**)((char*)end-bytes);}
};
struct G5aActorOwner{
 void **vtable;char unknown4[24];G5aActorStorage storage;char unknown32[12];
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
extern "C" void g5a_actor_cleanup_800fff24(G5aActorOwner*self,int flags){self->~G5aActorOwner();base_801628ec(self,flags);}
