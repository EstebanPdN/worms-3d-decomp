/* Observed vector layout: begin/end +0/+4, allocator word +8,
 * capacity end +12. Names inferred. Allocation and copy use typed inline
 * helpers to retain the original count-to-byte common subexpression. */
extern "C" {void *cx9c_allocate_80212fd4(unsigned int);void *cx9c_fallback_803413d8(unsigned int);void cx9c_free_802134fc(void *);void *cx9c_memmove_802eeef4(void *,const void *,unsigned int);}
static inline void *cx9c_storage(unsigned int bytes) {void *r=cx9c_allocate_80212fd4(bytes);if(!r)r=cx9c_fallback_803413d8(bytes);return r;}
struct Cx9cVector {void **begin,**end;unsigned int allocator;void **capacity;
 void commit(void **p,void **last) {begin=p;end=last;}
 void **allocate(unsigned int count) {
  return count?(void **)cx9c_storage(count*sizeof(void *)):0;
 }
 void **allocate_copy(unsigned int count,void **first,void **last) {
  void **tmp=allocate(count);if(last!=first)cx9c_memmove_802eeef4(tmp,first,(char *)last-(char *)first);return tmp;
 }
};
extern "C" void w3d_cx9c_pointer_reserve_803445d8(Cx9cVector *self,unsigned int requested) {
 if((unsigned int)(self->capacity-self->begin)<requested) {
  unsigned int count=self->end-self->begin;void **replacement;
  if(self->begin) {replacement=self->allocate_copy(requested,self->begin,self->end);if(self->begin)cx9c_free_802134fc(self->begin);}
  else replacement=self->allocate(requested);
  void **new_end=(void **)((count<<2)+(unsigned int)replacement);void **new_capacity=(void **)((requested<<2)+(unsigned int)replacement);self->begin=replacement;self->end=new_end;*(void ***)&self->capacity=new_capacity;
 }
}
