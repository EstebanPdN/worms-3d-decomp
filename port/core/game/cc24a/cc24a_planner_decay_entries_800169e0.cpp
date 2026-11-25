#include "w3d_ptr.h"
#line 1 "cc24a_planner_decay_entries_800169e0.cpp"
// Original influence decay and compacting removal. No normalization of copy overlap.
struct cc24a_DecayEntry_800169e0 {int unknown0;float cost;};
struct cc24a_DecayRange_800169e0 {Ptr32<Ptr32<cc24a_DecayEntry_800169e0>> begin; Ptr32<Ptr32<cc24a_DecayEntry_800169e0>> end;int size(){return end-begin;}};
extern "C" {extern Ptr32<cc24a_DecayRange_800169e0> cc24a_entries_804aa700;
 void cc24a_destroy_80015d18(Ptr32<cc24a_DecayEntry_800169e0>,int);
 Ptr32<void> cc24a_copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned int,...);
}
inline void cc24a_copy_tail_800169e0(Ptr32<Ptr32<cc24a_DecayEntry_800169e0>> destination,Ptr32<Ptr32<cc24a_DecayEntry_800169e0>> next,Ptr32<Ptr32<cc24a_DecayEntry_800169e0>> end){
 unsigned int bytes=(unsigned int)((Ptr32<char>)end-(Ptr32<char>)destination);
 cc24a_copy_802eee50(destination,next,bytes);
}
extern "C" void cc24a_planner_decay_entries_800169e0(){
 for(int i=0;i<cc24a_entries_804aa700->size();++i){
  Ptr32<cc24a_DecayEntry_800169e0> entry=*(Ptr32<Ptr32<cc24a_DecayEntry_800169e0>>)((Ptr32<char>)cc24a_entries_804aa700->begin+(i<<2));
  entry->cost*=0.8999999761581421f;
  if(entry->cost<0.10000000149011612f){
   if(entry)cc24a_destroy_80015d18(entry,3);
   Ptr32<cc24a_DecayRange_800169e0> range=cc24a_entries_804aa700;
   Ptr32<Ptr32<cc24a_DecayEntry_800169e0>> slot=(Ptr32<Ptr32<cc24a_DecayEntry_800169e0>>)w3d::G(((i<<2)+(unsigned int)w3d::H(range->begin)));
   if(slot+1!=range->end)cc24a_copy_tail_800169e0(slot,slot+1,range->end-1);
   --range->end;--i;
  }
 }
}


