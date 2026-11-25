// Inferred partial owner and queue views. Unknown fields are retained only to
// express witnessed offsets; this does not establish the complete class size.
struct cc42a_UpdateOwner;
struct cc42a_UpdateVtable {
 void* unknown00[17]; int (*begin)(cc42a_UpdateOwner*);
 void* unknown48[13]; int (*apply)(cc42a_UpdateOwner*,unsigned int);
};
struct cc42a_UpdateQueue { unsigned int* begin; unsigned int* end; };
struct cc42a_UpdateOwner { cc42a_UpdateVtable* vtable; unsigned char unknown04[16];
 unsigned int flags; unsigned char unknown18[9764]; cc42a_UpdateQueue queue; };
extern "C" int cc42a_update_8017e49c(cc42a_UpdateOwner*,float);
extern "C" void* cc42a_slots_803439d8();
extern "C" void cc42a_slots_update_8019831c(void*);
extern "C" int cc42a_flush_updates_8017d760(cc42a_UpdateOwner* self,float delta) {
 if((int)self->flags<0) {
  self->flags |= 0x40000000;
  self->vtable->begin(self);
  cc42a_update_8017e49c(self,delta);
  self->flags &= ~0x40000000u;
  cc42a_UpdateQueue* queue=&self->queue;
  for(unsigned int* p=queue->begin;p!=queue->end;) {
   unsigned int value=*p++;
   self->vtable->apply(self,value);
  }
  queue->end=queue->begin;
  cc42a_slots_update_8019831c(cc42a_slots_803439d8());
 }
 return 0;
}
