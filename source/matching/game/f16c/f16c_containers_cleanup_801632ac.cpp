// Inferred external prefix layouts; no object of these types is constructed here.
extern "C" void scalarfree_801fe1f8(void*),arrayfree_801fe240(void*),holder_8034aef4(void*),close_80210abc(void*,int),defer_80210afc(void*),arena_801613b8(void*),prepare_80164f88(void*);
struct F16cContainerObject{void **vtable;};
struct F16cContainerEntry{char unknown0[12];F16cContainerObject *held;char unknown16[20];~F16cContainerEntry(){if(held)((void(*)(F16cContainerObject*))held->vtable[4])(held);}};
struct F16cContainerBuffer{static void operator delete(void*);void *begin;~F16cContainerBuffer(){if(begin)arrayfree_801fe240(begin);begin=0;}};
struct F16cContainerList{unsigned unknown[3];};
struct F16cContainerDeferred{unsigned unknown[3];~F16cContainerDeferred(){close_80210abc(this,2);}};
struct F16cContainer{
 static void operator delete(void*);
 F16cContainerEntry *entries;char unknown4[20];F16cContainerBuffer *a,*b;char unknown32[8];F16cContainerList lists[3];F16cContainerDeferred deferred;
 ~F16cContainer(){
  for(unsigned i=0;i<3;++i)holder_8034aef4(&lists[i]);
  delete b;b=0;
  delete a;a=0;
  if(entries){F16cContainerEntry *end=entries+((unsigned*)entries)[-2];while(entries!=end){--end;end->~F16cContainerEntry();}arrayfree_801fe240((char*)entries-8);}entries=0;
 }
};
struct F16cContainerOwner{char unknown0[20];F16cContainer *a,*b,*c;void *arena;};
extern "C" int f16c_containers_cleanup_801632ac(F16cContainerOwner*self){
 prepare_80164f88(self);defer_80210afc(&self->c->deferred);arena_801613b8(&self->arena);
 delete self->a;self->a=0;
 delete self->b;self->b=0;return 0;
}
