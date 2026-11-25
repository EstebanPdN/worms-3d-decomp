#include "w3d_ptr.h"
#line 1 "g1c_named_slot_select_v2_800a7e14.cpp"
struct G1cSeekOwnerPrefix;
struct G1cSlotView { Ptr32<int> base; template <class W3dU> G1cSlotView(Ptr32<W3dU> w3d_p) : G1cSlotView((int *)w3d_p.get()) {}
 G1cSlotView(int *p):base(p){} int &operator[](unsigned index){return base[index];} };
inline G1cSlotView selectedSlots(Ptr32<G1cSeekOwnerPrefix> owner) {return G1cSlotView((Ptr32<int>)((Ptr32<char>)(Ptr32<void>)owner+132));}
extern "C" Ptr32<G1cSeekOwnerPrefix> owner_804aac54;
extern "C" const char empty_803814dc[];
extern "C" int compare_802ef234(Ptr32<const char>,Ptr32<const char>);
extern "C" int find_800a7da4(Ptr32<G1cSeekOwnerPrefix>,Ptr32<const char>);
extern "C" void seek_800a7ee4(Ptr32<G1cSeekOwnerPrefix>);
extern "C" void g1c_named_slot_select_v2_800a7e14(unsigned slot,Ptr32<const char> name) {
 if(!name || compare_802ef234(name,empty_803814dc)==0) {
  Ptr32<G1cSeekOwnerPrefix> owner=owner_804aac54;selectedSlots(owner)[slot]=-1;seek_800a7ee4(owner);
 } else {
  int found=find_800a7da4(owner_804aac54,name);
  if(found>=0){Ptr32<G1cSeekOwnerPrefix> owner=owner_804aac54;selectedSlots(owner)[slot]=found;seek_800a7ee4(owner);}
 }
}


