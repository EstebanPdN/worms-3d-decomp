#include "w3d_ptr.h"
#line 1 "g4a_detail_registry_clear_800bb3a0.cpp"
// External partial layouts only; no local construction or complete extent claim.
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned,...);
struct G4aRange {
 Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end;
 unsigned size()const{return end-begin;}
 void clear(){Ptr32<Ptr32<void>> first=begin; Ptr32<Ptr32<void>> last=end;int removed=(Ptr32<char>)last-(Ptr32<char>)first;copy_802eee50(first,last,(Ptr32<char>)end-(Ptr32<char>)last);end=(Ptr32<Ptr32<void>>)((Ptr32<char>)end-removed);}
 };
struct G4aRegistry {char unknown0[68];int mode;char unknown72[44];G4aRange extra;};
struct G4aHeap {unsigned observed;};
extern G4aRange range_8043bb64[];
extern Ptr32<void> block_804b182c; extern Ptr32<void> block_804b1830; extern Ptr32<void> block_804b1834;
extern G4aHeap heap_804adde4;
extern "C" void release_800b8e50(Ptr32<void>),destroy_800b12f0(Ptr32<void>,int),release_80209920(Ptr32<G4aHeap>,Ptr32<void>);
extern "C" int g4a_detail_registry_clear_800bb3a0(Ptr32<G4aRegistry> self){
 int zero=0;unsigned i;
 for(i=zero;i<range_8043bb64[0].size();i++){
  release_800b8e50(*(Ptr32<Ptr32<void>>)((Ptr32<char>)range_8043bb64[0].begin+(i<<2)));
  if(*(Ptr32<Ptr32<void>>)((Ptr32<char>)range_8043bb64[0].begin+(i<<2)))destroy_800b12f0(*(Ptr32<Ptr32<void>>)((Ptr32<char>)range_8043bb64[0].begin+(i<<2)),3);
  *(Ptr32<Ptr32<void>>)((Ptr32<char>)range_8043bb64[0].begin+(i<<2))=0;
 }
 if(block_804b182c){release_80209920(&heap_804adde4,block_804b182c);release_80209920(&heap_804adde4,block_804b1830);release_80209920(&heap_804adde4,block_804b1834);}
 range_8043bb64[0].clear();self->extra.clear();self->mode=0;return 0;
}


