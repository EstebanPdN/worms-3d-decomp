// Complete local vector is four floats, copied in full. All receivers are
// partial external views and are never allocated or constructed locally.
struct G1bVector3 {float x,y,z;G1bVector3(const G1bVector3&q){float a=q.x,b=q.y,c=q.z;x=a;y=b;z=c;}};
struct G1bVector4:G1bVector3 {float w;G1bVector4(const G1bVector4&q):G1bVector3(q),w(q.w){}};
struct G1bCallback {unsigned unknown;unsigned short unknown4,index;unsigned prefix[8];int mode;};
struct G1bSecondary {char prefix[24];void**callbacks;};
inline int invokeCallback(G1bSecondary*self,G1bCallback*callback){return ((int(*)(G1bSecondary*,G1bCallback*))self->callbacks[callback->index])(self,callback);}
struct G1bItem {char prefix[48];G1bCallback*callback;};
struct G1bOwner {void**table;unsigned prefix[6];void**callbacks;unsigned unknown[13];unsigned active;};
extern "C" int fn_801a572c(void*,G1bItem*);
extern G1bVector4 value_8045e62c;
extern "C" int g1b_scope_dispatch_801a5df8(char*self,G1bItem*item){
 G1bOwner*owner=self?(G1bOwner*)(self-4):0;
 int result=fn_801a572c(self,item);
 if(result>=0){G1bCallback*callback=item->callback;
  if(callback&&callback->mode==1){
   G1bVector4 saved=*((G1bVector4*(*)(G1bOwner*))owner->table[16])(owner);
   unsigned flags=((unsigned(*)(G1bOwner*))owner->table[15])(owner);
   ((void(*)(G1bOwner*,unsigned))owner->table[14])(owner,flags|8);
   ((void(*)(G1bOwner*,const G1bVector4*))owner->table[17])(owner,&value_8045e62c);
   owner->active=1;
   invokeCallback((G1bSecondary*)((char*)owner+4),callback);
   ((void(*)(G1bOwner*,const G1bVector4*))owner->table[17])(owner,&saved);
   owner->active=0;
   ((void(*)(G1bOwner*,unsigned))owner->table[14])(owner,flags);
  }
  result=0;
 }
 return result;
}
