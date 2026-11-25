#include "w3d_ptr.h"
#line 1 "cx10b_service_chain_append_8020abe0.cpp"
// Observed raw pointer-vector storage at owner +20; length arithmetic uses bytes.
struct Interface;struct Vtable {Ptr32<void> reserved[3];Ptr32<int (Ptr32<Interface>)> retain;};struct Interface {Ptr32<Vtable> vtable;};
extern "C" Ptr32<void> allocate_80212fd4(unsigned int);
extern "C" void free_802134fc(Ptr32<void>);
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned int,...);
static inline const int &maximum(const int &a,const int &b){return a<b?b:a;}
static inline const unsigned int &minimum(const unsigned int &a,const unsigned int &b){return b<a?b:a;}
struct Slots {Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
 void push(Ptr32<Interface> const &value) {
  if(end==capacity) {
   unsigned int used=end-begin;
   unsigned int bytes=maximum((int)used+1,(int)(used+(used>>1)))<<2;
   Ptr32<unsigned char> data=(Ptr32<unsigned char>)allocate_80212fd4(bytes);
   if(begin){copy_802eee50(data,begin,minimum(bytes,used));free_802134fc(begin);}
   begin=data;end=data+used;capacity=data+bytes;
  }
  *(Ptr32<Ptr32<Interface>>)end=value;end+=4;
 }
};
struct Owner {unsigned char opaque[20];Slots slots;};

extern "C" int w3d_cx10b_service_chain_append_8020abe0(Ptr32<Owner> self,Ptr32<Interface> value) {
 if(!value || (Ptr32<void>)value==(Ptr32<void>)self)return (int)0x80004005;
 self->slots.push(value);value->vtable->retain(value);return 0;
}



