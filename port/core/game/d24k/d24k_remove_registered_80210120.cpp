#include "w3d_ptr.h"
#line 1 "d24k_remove_registered_80210120.cpp"
// Removes an interface from a registered list (Worms 3D GameCube PAL, 0x80210120).
//
// std::remove over the reference-counted slots of the list 0x80463be0: finds
// the first match (0x8035d164), copies the remaining non-matching entries down
// (retain the new, release the old) and erases the tail through 0x80210dd8. The
// comparison value is loaded through its reference into a loop local before the
// entry. All identities are inferred.
namespace d24k_rr {
struct Interface;
typedef Ptr32<void (Ptr32<Interface>)> VirtualCall;
struct Interface {Ptr32<VirtualCall> vtable;};
struct Slot {
 Ptr32<Interface> pointer;
 Slot &operator=(const Slot &other) {
  if(other.pointer)
   other.pointer->vtable[3](other.pointer);
  if(pointer)
   pointer->vtable[4](pointer);
  pointer=other.pointer;
  return *this;
 }
};
struct List {unsigned count,capacity; Ptr32<Slot> items;};
extern "C" List lbl_80463be0;
extern "C" Ptr32<Slot> fn_8035d164(Ptr32<Slot>,Ptr32<Slot>,Ptr32<Ptr32<Interface> const>);
extern "C" void fn_80210dd8(Ptr32<List>,Ptr32<Slot>,Ptr32<Slot>);
inline Ptr32<Slot> remove_copy(Ptr32<Slot> first,Ptr32<Slot> last,Ptr32<Slot> result,Ptr32<Interface> const &value) {
 for(;first!=last;++first) {
  Ptr32<Interface> v=value;
  if(first->pointer!=v) { *result=*first; ++result; }
 }
 return result;
}
inline Ptr32<Slot> remove(Ptr32<Slot> first,Ptr32<Slot> last,Ptr32<Interface> const &value) {
 first=fn_8035d164(first,last,&value);
 if(first==last)return first;
 Ptr32<Slot> next=first;
 return remove_copy(++next,last,first,value);
}
}
extern "C" void w3d_d24k_remove_registered_80210120(Ptr32<d24k_rr::Interface> value) {
 using namespace d24k_rr;
 Ptr32<Slot> end=lbl_80463be0.items+lbl_80463be0.count;
 Ptr32<Slot> newend=remove(lbl_80463be0.items,end,value);
 fn_80210dd8(&lbl_80463be0,newend,lbl_80463be0.items+lbl_80463be0.count);
}


