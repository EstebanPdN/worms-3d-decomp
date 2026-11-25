// Observed PPC32 byte-buffer pointer and size at zero and four.
struct Buffer {unsigned char *data;unsigned int size;};
struct Heap {unsigned int opaque[2];};
extern Heap heap_804b0644;
extern "C" void *allocate_802098d8(Heap *,unsigned int,int);
extern "C" void release_80209920(Heap *,void *);
extern "C" void *copy_802eee50(void *,const void *,unsigned int,...);
extern "C" void *clear_802eefe0(void *,int,unsigned int);
extern "C" void w3d_cx10b_record_buffer_grow_80207514(Buffer *self,unsigned int size,int flags) {
 if(size>self->size) {
  unsigned char *old=self->data;
  self->data=(unsigned char *)allocate_802098d8(&heap_804b0644,size,flags);
  copy_802eee50(self->data,old,self->size);
  clear_802eefe0(self->data+self->size,0,size-self->size);
  if(old)release_80209920(&heap_804b0644,old);
  self->size=size;
 }
}

