#include "w3d_ptr.h"
#line 1 "cx9c_pointer_reserve_803445d8.cpp"
/* Observed vector layout: begin/end +0/+4, allocator word +8,
 * capacity end +12. Names inferred. Allocation and copy use typed inline
 * helpers to retain the original count-to-byte common subexpression. */
extern "C" {Ptr32<void> cx9c_allocate_80212fd4(unsigned int);Ptr32<void> cx9c_fallback_803413d8(unsigned int);void cx9c_free_802134fc(Ptr32<void>);Ptr32<void> cx9c_memmove_802eeef4(Ptr32<void>,Ptr32<const void>,unsigned int);}
static inline Ptr32<void> cx9c_storage(unsigned int bytes) {Ptr32<void> r=cx9c_allocate_80212fd4(bytes);if(!r)r=cx9c_fallback_803413d8(bytes);return r;}
struct Cx9cVector {Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end;unsigned int allocator;Ptr32<Ptr32<void>> capacity;
 void commit(Ptr32<Ptr32<void>> p,Ptr32<Ptr32<void>> last) {begin=p;end=last;}
 Ptr32<Ptr32<void>> allocate(unsigned int count) {
  return count?w3d::R((Ptr32<Ptr32<void>>)cx9c_storage(count*sizeof(Ptr32<void>))):0;
 }
 Ptr32<Ptr32<void>> allocate_copy(unsigned int count,Ptr32<Ptr32<void>> first,Ptr32<Ptr32<void>> last) {
  Ptr32<Ptr32<void>> tmp=allocate(count);if(last!=first)cx9c_memmove_802eeef4(tmp,first,(Ptr32<char>)last-(Ptr32<char>)first);return tmp;
 }
};
extern "C" void w3d_cx9c_pointer_reserve_803445d8(Ptr32<Cx9cVector> self,unsigned int requested) {
 if((unsigned int)(self->capacity-self->begin)<requested) {
  unsigned int count=self->end-self->begin;Ptr32<Ptr32<void>> replacement;
  if(self->begin) {replacement=self->allocate_copy(requested,self->begin,self->end);if(self->begin)cx9c_free_802134fc(self->begin);}
  else replacement=self->allocate(requested);
  Ptr32<Ptr32<void>> new_end=(Ptr32<Ptr32<void>>)w3d::G(((count<<2)+(unsigned int)w3d::H(replacement)));Ptr32<Ptr32<void>> new_capacity=(Ptr32<Ptr32<void>>)w3d::G(((requested<<2)+(unsigned int)w3d::H(replacement)));self->begin=replacement;self->end=new_end;*(Ptr32<Ptr32<Ptr32<void>>>)&self->capacity=new_capacity;
 }
}


