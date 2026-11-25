// UNPROVED RESEARCH SOURCE. No admission manifest or linked equality claim.
// GWMP8P 8034af90: inferred scheduler over three observed group descriptors.
// Native GC32 views only. External actor callbacks may mutate scheduling state.
// The caller supplies valid group/registry/heap storage and live interfaces.
inline void *operator new(unsigned,void *p) throw() { return p; }
namespace Sol35f10Scheduler8034af90 {
extern "C" void *sol35f10_scheduler_allocate_80212fd4(unsigned);
extern "C" void *sol35f10_scheduler_fallback_803413d8(unsigned);
extern "C" void sol35f10_scheduler_free_802134fc(void *);
extern "C" void *sol35f10_scheduler_move_802eeef4(void *,const void *,unsigned);
struct Context {unsigned words_00_34[14];unsigned stop,running;};
extern "C" Context *sol35f10_scheduler_context_80165254();
extern "C" unsigned sol35f10_scheduler_service_flag_804ab4d8;
extern "C" Context *sol35f10_scheduler_global_context_804b178c;
extern "C" void sol35f10_scheduler_service_801651e4(Context *);
struct Event {
 unsigned handle,time;
 Event(const unsigned &h,const unsigned &t):handle(h),time(t){}
};
template<class T> struct Allocator {
 static void *storage(unsigned bytes){
  void *p=sol35f10_scheduler_allocate_80212fd4(bytes);
  if(!p)p=sol35f10_scheduler_fallback_803413d8(bytes);
  return p;
 }
 T *allocate(unsigned n){return n?(T *)storage(n*sizeof(T)):0;}
 void deallocate(T *p,unsigned){if(p)sol35f10_scheduler_free_802134fc(p);}
};
template<class T> struct Storage:Allocator<T>{T *data;};
struct Trivial{};struct Nontrivial{};
template<class T> inline const T &maximum(const T &a,const T &b){return a<b?b:a;}
template<class T> inline void construct(T *p,const T &x){new(p) T(x);}
template<class T> inline T *copy(const T *a,const T *b,T *out,const Nontrivial &){
 for(;a!=b;++a,++out)construct(out,*a);return out;
}
template<class T> inline T *copy(const T *a,const T *b,T *out,const Trivial &){
 if(b!=a){unsigned bytes=(const char *)b-(const char *)a;
  return (T *)((char *)sol35f10_scheduler_move_802eeef4(out,a,bytes)+bytes);}
 return out;
}
template<class T> inline T *fill(T *out,unsigned n,const T &x,const Nontrivial &){
 for(;n;--n,++out)construct(out,x);return out;
}
template<class T> inline T *fill(T *out,unsigned n,const T &x,const Trivial &){
 for(;n;--n,++out)*out=x;return out;
}
template<class T> inline void destroy_aux(T *a,T *b,const Nontrivial &){for(;a!=b;++a)a->~T();}
template<class T> inline void destroy_aux(T *,T *,const Trivial &){}
template<class T,class Tag> struct Vector {
 T *start,*finish;Storage<T> storage;
 unsigned size()const{return finish-start;}
 T *begin(){return start;} T *end(){return finish;}
 void clear_storage(){destroy_aux(start,finish,Tag());storage.deallocate(start,storage.data-start);}
 void set(T *s,T *f,T *e){start=s;finish=f;storage.data=e;}
 void overflow(T *pos,const T &x,unsigned n){
  const unsigned old_size=size();
  const unsigned length=old_size+maximum(old_size,n);
  T *new_start=storage.allocate(length);
  T *new_finish=new_start;
  new_finish=copy((const T *)start,(const T *)pos,new_finish,Tag());
  if(n==1){construct(new_finish,x);++new_finish;}
  else new_finish=fill(new_finish,n,x,Tag());
  clear_storage();set(new_start,new_finish,new_start+length);
 }
 void push_back(const T &x){
  if(finish!=storage.data){construct(finish,x);++finish;}
  else overflow(finish,x,1);
 }
};
template<> inline void Vector<unsigned,Trivial>::overflow(unsigned *pos,const unsigned &x,unsigned n){
 const unsigned old_size=size();
 const unsigned length=old_size+maximum(old_size,n);
 unsigned *new_start=storage.allocate(length);
 unsigned *new_finish=copy((const unsigned *)start,(const unsigned *)pos,new_start,Trivial());
 new_finish=fill(new_finish,n,x,Trivial());
 clear_storage();set(new_start,new_finish,new_start+length);
}
typedef Vector<Event,Nontrivial> EventVector;
struct Heap:EventVector{unsigned char compare_tag;};
typedef Vector<unsigned,Trivial> ReadyVector;
extern "C" void sol35f10_scheduler_pop_8034a7fc(Event *,Event *,const unsigned char *);
extern "C" void sol35f10_scheduler_push_8034a400(Event *,Event *,const unsigned char *);
struct Actor;
struct Methods {void (*slots_00_1c[8])();unsigned (*update)(Actor *,unsigned);};
struct Actor {Methods *methods;};
struct Record {
 unsigned word00,word04,word08;Actor *object;unsigned word10,handle,word18,word1c,word20;
};
struct Registry {Record *records;};
struct Group {Heap *pending;ReadyVector *ready;Registry *registry;};
extern "C" void sol35f10_scheduler_current_8034b3f8(Registry *,unsigned);
extern "C" void sol35f10_scheduler_stop_time_8034b408(Registry *,unsigned);
inline Record *lookup(Registry *registry,unsigned handle){
 Record *found;
 if(handle==~0u)found=0;
 else {Record *record=&registry->records[handle&0xfffu];found=0;if(record->handle==handle)found=record;}
 return found;
}
inline void set_running(unsigned n){sol35f10_scheduler_context_80165254()->running=n;}
typedef char EventSize[sizeof(Event)==8?1:-1];
typedef char VectorSize[sizeof(EventVector)==16?1:-1];
typedef char RecordSize[sizeof(Record)==36?1:-1];
typedef char GroupSize[sizeof(Group)==12?1:-1];
}
extern "C" void sol35f10_scheduler_8034af90(Sol35f10Scheduler8034af90::Group *groups,unsigned count,unsigned limit){
 using namespace Sol35f10Scheduler8034af90;
 set_running(1);
 while(!sol35f10_scheduler_context_80165254()->stop){
  unsigned group=3,time=~0u;
  for(unsigned i=0;i<count;++i){
   Heap *heap=groups[i].pending;
   if(heap->size()){
    unsigned candidate=heap->start->time;
    if(candidate<=limit&&candidate<time){time=candidate;group=i;}
   }
  }
  if(group==3)break;
  Group *selected=&groups[group];Heap *heap=selected->pending;
  unsigned event_handle=heap->start->handle;
  unsigned event_time=heap->start->time;
  unsigned char compare=heap->compare_tag;
  sol35f10_scheduler_pop_8034a7fc(heap->start,heap->finish,&compare);--heap->finish;
  Record *record=lookup(selected->registry,event_handle);
  if(record){
   sol35f10_scheduler_current_8034b3f8(selected->registry,event_time);
   Actor *actor=record->object;
   unsigned delta=actor->methods->update(actor,event_time);
   if(sol35f10_scheduler_context_80165254()->stop){
    limit=event_time;sol35f10_scheduler_stop_time_8034b408(selected->registry,event_time);
   }
   if(delta){
    if(delta!=~0u){
     Event next(event_handle,delta+event_time);heap->push_back(next);
     compare=heap->compare_tag;
     sol35f10_scheduler_push_8034a400(heap->start,heap->finish,&compare);
    }
   }else {unsigned ready_handle=event_handle;selected->ready->push_back(ready_handle);}
  }
  if(sol35f10_scheduler_service_flag_804ab4d8)
   sol35f10_scheduler_service_801651e4(sol35f10_scheduler_global_context_804b178c);
 }
 set_running(0);
}
