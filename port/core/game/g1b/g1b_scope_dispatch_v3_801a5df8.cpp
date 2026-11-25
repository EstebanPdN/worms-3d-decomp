#include "w3d_ptr.h"
#line 1 "g1b_scope_dispatch_v3_801a5df8.cpp"
// Complete local vector is four floats, copied in full. All receivers are
// partial external views and are never allocated or constructed locally.
struct G1bVector3 {float x,y,z;G1bVector3(const G1bVector3&q){float a=q.x,b=q.y,c=q.z;x=a;y=b;z=c;}};
struct G1bVector4:G1bVector3 {float w __attribute__((aligned(__alignof__(G1bVector3))));G1bVector4(const G1bVector4&q):G1bVector3(q),w(q.w){}};
struct G1bCallback {unsigned unknown;unsigned short unknown4,index;unsigned prefix[8];int mode;};
struct G1bSecondary {char prefix[24];Ptr32<Ptr32<void>> callbacks;};
inline int invokeCallback(Ptr32<G1bSecondary> self,Ptr32<G1bCallback> callback){return ((Ptr32<int (Ptr32<G1bSecondary>, Ptr32<G1bCallback>)>)self->callbacks[callback->index])(self,callback);}
struct G1bItem {char prefix[48];Ptr32<G1bCallback> callback;};
struct G1bOwner {Ptr32<Ptr32<void>> table;unsigned prefix[6];Ptr32<Ptr32<void>> callbacks;unsigned unknown[13];unsigned active;};
extern "C" int fn_801a572c(Ptr32<void>,Ptr32<G1bItem>);
extern G1bVector4 value_8045e62c;
extern "C" int g1b_scope_dispatch_801a5df8(Ptr32<char> self,Ptr32<G1bItem> item){
 Ptr32<G1bOwner> owner=self?w3d::R((Ptr32<G1bOwner>)(self-4)):0;
 int result=fn_801a572c(self,item);
 if(result>=0){Ptr32<G1bCallback> callback=item->callback;
  if(callback&&callback->mode==1){
   G1bVector4 saved=*((Ptr32<Ptr32<G1bVector4> (Ptr32<G1bOwner>)>)owner->table[16])(owner);
   unsigned flags=((Ptr32<unsigned int (Ptr32<G1bOwner>)>)owner->table[15])(owner);
   ((Ptr32<void (Ptr32<G1bOwner>, unsigned int)>)owner->table[14])(owner,flags|8);
   ((Ptr32<void (Ptr32<G1bOwner>, Ptr32<const G1bVector4>)>)owner->table[17])(owner,&value_8045e62c);
   owner->active=1;
   invokeCallback((Ptr32<G1bSecondary>)((Ptr32<char>)owner+4),callback);
   ((Ptr32<void (Ptr32<G1bOwner>, Ptr32<const G1bVector4>)>)owner->table[17])(owner,&saved);
   owner->active=0;
   ((Ptr32<void (Ptr32<G1bOwner>, unsigned int)>)owner->table[14])(owner,flags);
  }
  result=0;
 }
 return result;
}


