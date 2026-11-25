// Partial native GC32 interface-list view; all identities remain inferred.
namespace sol35d8_remove_registered_v2 {
struct Interface;
typedef void (*VirtualCall)(Interface *);
struct Interface {VirtualCall *vtable;};
struct Slot {
 Interface *pointer;
 Slot &operator=(const Slot &other) {
  if(other.pointer)
   other.pointer->vtable[3](other.pointer);
  if(pointer)
   pointer->vtable[4](pointer);
  pointer=other.pointer;
  return *this;
 }
};
struct List {unsigned count,capacity; Slot *items;};
extern "C" List lbl_80463be0;
extern "C" Slot *fn_8035d164(Slot *,Slot *,Interface *const *);
extern "C" void fn_80210dd8(List *,Slot *,Slot *);
inline Slot *remove(Slot *first,Slot *last,Interface *const &value) {
 first=fn_8035d164(first,last,&value);
 if(first==last)return first;
 Slot *result=first;
 ++first;
 for(;first!=last;++first) {
  if(first->pointer!=value) {
   *result=*first;
   ++result;
  }
 }
 return result;
}
typedef char SlotSize[(sizeof(Slot)==4)?1:-1];
typedef char ListSize[(sizeof(List)==12)?1:-1];
}
extern "C" void sol35d8_remove_registered_80210120_v2(sol35d8_remove_registered_v2::Interface *value) {
 using namespace sol35d8_remove_registered_v2;
 Slot *end=lbl_80463be0.items+lbl_80463be0.count;
 Slot *newend=remove(lbl_80463be0.items,end,value);
 fn_80210dd8(&lbl_80463be0,newend,lbl_80463be0.items+lbl_80463be0.count);
}
