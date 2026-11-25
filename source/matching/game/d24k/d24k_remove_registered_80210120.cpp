// Removes an interface from a registered list (Worms 3D GameCube PAL, 0x80210120).
//
// std::remove over the reference-counted slots of the list 0x80463be0: finds
// the first match (0x8035d164), copies the remaining non-matching entries down
// (retain the new, release the old) and erases the tail through 0x80210dd8. The
// comparison value is loaded through its reference into a loop local before the
// entry. All identities are inferred.
namespace d24k_rr {
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
inline Slot *remove_copy(Slot *first,Slot *last,Slot *result,Interface *const &value) {
 for(;first!=last;++first) {
  Interface *v=value;
  if(first->pointer!=v) { *result=*first; ++result; }
 }
 return result;
}
inline Slot *remove(Slot *first,Slot *last,Interface *const &value) {
 first=fn_8035d164(first,last,&value);
 if(first==last)return first;
 Slot *next=first;
 return remove_copy(++next,last,first,value);
}
}
extern "C" void w3d_d24k_remove_registered_80210120(d24k_rr::Interface *value) {
 using namespace d24k_rr;
 Slot *end=lbl_80463be0.items+lbl_80463be0.count;
 Slot *newend=remove(lbl_80463be0.items,end,value);
 fn_80210dd8(&lbl_80463be0,newend,lbl_80463be0.items+lbl_80463be0.count);
}
