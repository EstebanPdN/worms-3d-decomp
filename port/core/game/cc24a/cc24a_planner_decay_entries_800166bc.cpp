#include "w3d_ptr.h"
#line 1 "cc24a_planner_decay_entries_800166bc.cpp"
// Original influence decay and compacting removal. No normalization of copy overlap.
struct cc24a_DecayEntry_800166bc {int unknown0;float cost;};
struct cc24a_DecayRange_800166bc {Ptr32<Ptr32<cc24a_DecayEntry_800166bc>> begin; Ptr32<Ptr32<cc24a_DecayEntry_800166bc>> end;int size(){return end-begin;}};
extern "C" {extern Ptr32<cc24a_DecayRange_800166bc> cc24a_entries_804aa6fc;
 void cc24a_destroy_80015d18(Ptr32<cc24a_DecayEntry_800166bc>,int);
 Ptr32<void> cc24a_copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned int,...);
}
inline void cc24a_copy_tail_800166bc(Ptr32<Ptr32<cc24a_DecayEntry_800166bc>> destination,Ptr32<Ptr32<cc24a_DecayEntry_800166bc>> next,Ptr32<Ptr32<cc24a_DecayEntry_800166bc>> end){
 unsigned int bytes=(unsigned int)((Ptr32<char>)end-(Ptr32<char>)destination);
 cc24a_copy_802eee50(destination,next,bytes);
}
extern "C" void cc24a_planner_decay_entries_800166bc(){
 for(int i=0;i<cc24a_entries_804aa6fc->size();++i){
  Ptr32<cc24a_DecayEntry_800166bc> entry=*(Ptr32<Ptr32<cc24a_DecayEntry_800166bc>>)((Ptr32<char>)cc24a_entries_804aa6fc->begin+(i<<2));
  entry->cost*=0.949999988079071f;
  if(entry->cost<0.10000000149011612f){
   if(entry)cc24a_destroy_80015d18(entry,3);
   Ptr32<cc24a_DecayRange_800166bc> range=cc24a_entries_804aa6fc;
   Ptr32<Ptr32<cc24a_DecayEntry_800166bc>> slot=(Ptr32<Ptr32<cc24a_DecayEntry_800166bc>>)w3d::G(((i<<2)+(unsigned int)w3d::H(range->begin)));
   if(slot+1!=range->end)cc24a_copy_tail_800166bc(slot,slot+1,range->end-1);
   --range->end;--i;
  }
 }
}


