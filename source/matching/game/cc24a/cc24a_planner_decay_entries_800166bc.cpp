// Original influence decay and compacting removal. No normalization of copy overlap.
struct cc24a_DecayEntry_800166bc {int unknown0;float cost;};
struct cc24a_DecayRange_800166bc {cc24a_DecayEntry_800166bc **begin,**end;int size(){return end-begin;}};
extern "C" {extern cc24a_DecayRange_800166bc *cc24a_entries_804aa6fc;
 void cc24a_destroy_80015d18(cc24a_DecayEntry_800166bc*,int);
 void *cc24a_copy_802eee50(void*,const void*,unsigned int,...);
}
inline void cc24a_copy_tail_800166bc(cc24a_DecayEntry_800166bc **destination,cc24a_DecayEntry_800166bc **next,cc24a_DecayEntry_800166bc **end){
 unsigned int bytes=(unsigned int)((char*)end-(char*)destination);
 cc24a_copy_802eee50(destination,next,bytes);
}
extern "C" void cc24a_planner_decay_entries_800166bc(){
 for(int i=0;i<cc24a_entries_804aa6fc->size();++i){
  cc24a_DecayEntry_800166bc *entry=*(cc24a_DecayEntry_800166bc**)((char*)cc24a_entries_804aa6fc->begin+(i<<2));
  entry->cost*=0.949999988079071f;
  if(entry->cost<0.10000000149011612f){
   if(entry)cc24a_destroy_80015d18(entry,3);
   cc24a_DecayRange_800166bc *range=cc24a_entries_804aa6fc;
   cc24a_DecayEntry_800166bc **slot=(cc24a_DecayEntry_800166bc**)((i<<2)+(unsigned int)range->begin);
   if(slot+1!=range->end)cc24a_copy_tail_800166bc(slot,slot+1,range->end-1);
   --range->end;--i;
  }
 }
}
