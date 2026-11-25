// Observed raw pointer-vector storage at owner +20; length arithmetic uses bytes.
struct Interface;struct Vtable {void *reserved[3];int (*retain)(Interface *);};struct Interface {Vtable *vtable;};
extern "C" void *allocate_80212fd4(unsigned int);
extern "C" void free_802134fc(void *);
extern "C" void *copy_802eee50(void *,const void *,unsigned int,...);
static inline const int &maximum(const int &a,const int &b){return a<b?b:a;}
static inline const unsigned int &minimum(const unsigned int &a,const unsigned int &b){return b<a?b:a;}
struct Slots {unsigned char *begin,*end,*capacity;
 void push(Interface *const &value) {
  if(end==capacity) {
   unsigned int used=end-begin;
   unsigned int bytes=maximum((int)used+1,(int)(used+(used>>1)))<<2;
   unsigned char *data=(unsigned char *)allocate_80212fd4(bytes);
   if(begin){copy_802eee50(data,begin,minimum(bytes,used));free_802134fc(begin);}
   begin=data;end=data+used;capacity=data+bytes;
  }
  *(Interface **)end=value;end+=4;
 }
};
struct Owner {unsigned char opaque[20];Slots slots;};

extern "C" int w3d_cx10b_service_chain_append_8020abe0(Owner *self,Interface *value) {
 if(!value || (void *)value==(void *)self)return (int)0x80004005;
 self->slots.push(value);value->vtable->retain(value);return 0;
}

