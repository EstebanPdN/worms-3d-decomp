// Actual I7 provider declaration and fields; native array object view inferred.
#include "sol35d13_retained_record_abi.hpp"
void *operator new[](size_t);
void operator delete[](void *);
namespace sol35p8_abi {
extern "C" void sol35d13_report_802fb7ac(const char *,...);
extern "C" const char sol35d13_allocation_message_803b35bc[];
struct Sol35d13ArraySlot {
 Interface *pointer;
 Sol35d13ArraySlot():pointer(0) {}
 ~Sol35d13ArraySlot() { if(pointer) pointer->release(); }
};
typedef char Sol35d13ArraySlotSize[sizeof(Sol35d13ArraySlot)==sizeof(Interface *)?1:-1];
inline void sol35d13_resize_signed(CountedRefs *self,int requested) {
 unsigned count=unsigned(requested);
 if(int(self->capacity)>=requested) {
  for(unsigned i=count;i<self->count;++i) {
   Interface **slots=self->slots;
   if(slots[i]) slots[i]->release();
   slots[i]=0;
  }
 } else {
  Sol35d13ArraySlot *replacement=new Sol35d13ArraySlot[count];
  if(!replacement) {
   sol35d13_report_802fb7ac(sol35d13_allocation_message_803b35bc,count);
   return;
  }
  if(self->slots) {
   for(unsigned i=0;i<self->count;++i) {
    Interface **slots=self->slots;
    if(slots[i]) slots[i]->retain();
    if(replacement[i].pointer) replacement[i].pointer->release();
    replacement[i].pointer=slots[i];
   }
   delete[] reinterpret_cast<Sol35d13ArraySlot *>(self->slots);
  }
  self->capacity=count;
  self->slots=reinterpret_cast<Interface **>(replacement);
 }
 self->count=count;
}
extern "C" void sol35d13_resize_refs_80210b90_signed_boundary(CountedRefs *self,unsigned count) {
 sol35d13_resize_signed(self,int(count));
}
}
