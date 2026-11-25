// Complete local16B vector; partial external owners are never constructed.
struct Vector3 {float x,y,z;Vector3(const Vector3&q){float a=q.x,b=q.y,c=q.z;x=a;y=b;z=c;}};
struct Vector4:Vector3 {float w;Vector4(const Vector4&q):Vector3(q),w(q.w){}};
struct Callback {unsigned unknown;unsigned short unknown4,index;};
struct List {char unknown[24];unsigned count;unsigned unknown28;Callback*entries[1];};
struct Item {char unknown[20];Vector4 value;unsigned unknown36;unsigned accumulate;List*callbacks;};
struct Owner {void**table;char unknown4[24];void**callbacks;char unknown32[12];Vector4 value;char unknown60[24];unsigned active,flags;};
struct Secondary;
extern Vector4 default_8045e63c;
extern "C" Vector4*fn_801f53bc(Vector4*,const Vector4*,const Vector4*);
extern "C" int g2b_accumulate_callbacks_801a572c(char*self,Item*item){
 Owner*owner=self?(Owner*)(self-4):0;
 if(!item->accumulate){((void(*)(Owner*,const Vector4*))owner->table[17])(owner,&item->value);return 0;}
 Vector4 value(default_8045e63c);
 if(owner->active)value=*((Vector4*(*)(Owner*))owner->table[16])(owner);
 void**callbacks=owner->callbacks;
 Callback**begin=item->callbacks->entries;
 Callback**end=begin+item->callbacks->count;
 for(;begin!=end;++begin){
  Callback*callback=*begin;
  int result=((int(*)(Secondary*,Callback*))callbacks[callback->index])(owner?(Secondary*)((char*)owner+4):0,callback);
  if(result<0)return result;
  fn_801f53bc(&value,&value,&owner->value);
 }
 item->value=value;
 ((void(*)(Owner*,const Vector4*))owner->table[17])(owner,&value);
 if(owner->flags&8)item->accumulate=0;
 return 0;
}
