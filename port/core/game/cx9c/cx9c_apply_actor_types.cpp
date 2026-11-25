#include "w3d_ptr.h"
#line 1 "cx9c_apply_actor_types.cpp"
/* Observed type chain: next +4, parent +20. Actor callback is vtable +36;
 * negative results stop traversal. Names and type meanings are inferred. */
struct Cx9cActor {Ptr32<Ptr32<void>> vtable;};
struct Cx9cType {unsigned int opaque;Ptr32<Cx9cType> next;unsigned int other[3];Ptr32<Cx9cType> parent;};
extern "C" Ptr32<Cx9cActor> cx9c_first_8020fe00(Ptr32<Cx9cType>);
extern "C" Ptr32<Cx9cActor> cx9c_next_8020fe18(Ptr32<Cx9cType>,Ptr32<Cx9cActor>);
extern "C" Ptr32<Cx9cType> cx9c_types_8020ff3c();
static inline int cx9c_apply(Ptr32<Cx9cType> type,Ptr32<void> argument) {
 for(Ptr32<Cx9cActor> p=cx9c_first_8020fe00(type);p;p=cx9c_next_8020fe18(type,p)) {
  int result=((Ptr32<int (Ptr32<Cx9cActor>, Ptr32<void>)>)p->vtable[9])(p,argument);
  if(result<0)return result;
 }
 return 0;
}
static inline bool cx9c_descends(Ptr32<Cx9cType> type,Ptr32<Cx9cType> base) {
 while(type!=base) {Ptr32<Cx9cType> parent=type->parent;if(type==parent)return false;type=parent;}
 return true;
}
extern "C" int w3d_cx9c_apply_actor_types_8034ad50(Ptr32<void>,Ptr32<void> argument,Ptr32<Cx9cType> type,int descendants) {
 int result=cx9c_apply(type,argument);
 if(result>=0) {
  if(descendants)for(Ptr32<Cx9cType> p=cx9c_types_8020ff3c();p;p=p->next) {
   if(cx9c_descends(p,type) && p!=type) {int r=cx9c_apply(p,argument);if(r<0)return r;}
  }
  result=0;
 }
 return result;
}


