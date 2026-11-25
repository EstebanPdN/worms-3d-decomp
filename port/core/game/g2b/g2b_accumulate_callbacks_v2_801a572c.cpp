#include "w3d_ptr.h"
#line 1 "g2b_accumulate_callbacks_v2_801a572c.cpp"
// Complete local16B vector; partial external owners are never constructed.
struct Vector3 {float x,y,z;Vector3(const Vector3&q){float a=q.x,b=q.y,c=q.z;x=a;y=b;z=c;}};
struct Vector4:Vector3 {float w __attribute__((aligned(__alignof__(Vector3))));Vector4(const Vector4&q):Vector3(q),w(q.w){}};
struct Callback {unsigned unknown;unsigned short unknown4,index;};
struct List;
inline unsigned count(Ptr32<const List> p){return *(Ptr32<const unsigned int>)((Ptr32<const char>)p+24);}
inline Ptr32<Ptr32<Callback>> entries(Ptr32<List> p){return (Ptr32<Ptr32<Callback>>)((Ptr32<char>)p+32);}
struct Item {char unknown[20];Vector4 value;unsigned unknown36;unsigned accumulate;Ptr32<List> callbacks;};
struct Owner {Ptr32<Ptr32<void>> table;char unknown4[24];Ptr32<Ptr32<void>> callbacks;char unknown32[12];Vector4 value;char unknown60[24];unsigned active,flags;};
struct Secondary;
extern Vector4 default_8045e63c;
extern "C" Ptr32<Vector4> fn_801f53bc(Ptr32<Vector4>,Ptr32<const Vector4>,Ptr32<const Vector4>);
extern "C" int g2b_accumulate_callbacks_v2_801a572c(Ptr32<char> self,Ptr32<Item> item){
 Ptr32<Owner> owner=self?w3d::R((Ptr32<Owner>)(self-4)):0;
 if(!item->accumulate){((Ptr32<void (Ptr32<Owner>, Ptr32<const Vector4>)>)owner->table[17])(owner,&item->value);return 0;}
 Vector4 value(default_8045e63c);
 if(owner->active)value=*((Ptr32<Ptr32<Vector4> (Ptr32<Owner>)>)owner->table[16])(owner);
 Ptr32<Ptr32<void>> callbacks=owner->callbacks;
 Ptr32<Ptr32<Callback>> begin=entries(item->callbacks);
 Ptr32<Ptr32<Callback>> end=begin+count(item->callbacks);
 for(;begin!=end;++begin){
  Ptr32<Callback> callback=*begin;
  int result=((Ptr32<int (Ptr32<Secondary>, Ptr32<Callback>)>)callbacks[callback->index])(owner?w3d::R((Ptr32<Secondary>)((Ptr32<char>)owner+4)):0,callback);
  if(result<0)return result;
  fn_801f53bc(&value,&value,&owner->value);
 }
 item->value=value;
 ((Ptr32<void (Ptr32<Owner>, Ptr32<const Vector4>)>)owner->table[17])(owner,&value);
 if(owner->flags&8)item->accumulate=0;
 return 0;
}


