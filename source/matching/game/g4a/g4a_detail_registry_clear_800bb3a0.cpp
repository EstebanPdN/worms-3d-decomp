// External partial layouts only; no local construction or complete extent claim.
extern "C" void *copy_802eee50(void*,const void*,unsigned,...);
struct G4aRange {
 void **begin,**end;
 unsigned size()const{return end-begin;}
 void clear(){void **first=begin,**last=end;int removed=(char*)last-(char*)first;copy_802eee50(first,last,(char*)end-(char*)last);end=(void**)((char*)end-removed);}
 };
struct G4aRegistry {char unknown0[68];int mode;char unknown72[44];G4aRange extra;};
struct G4aHeap {unsigned observed;};
extern G4aRange range_8043bb64[];
extern void *block_804b182c,*block_804b1830,*block_804b1834;
extern G4aHeap heap_804adde4;
extern "C" void release_800b8e50(void*),destroy_800b12f0(void*,int),release_80209920(G4aHeap*,void*);
extern "C" int g4a_detail_registry_clear_800bb3a0(G4aRegistry*self){
 int zero=0;unsigned i;
 for(i=zero;i<range_8043bb64[0].size();i++){
  release_800b8e50(*(void**)((char*)range_8043bb64[0].begin+(i<<2)));
  if(*(void**)((char*)range_8043bb64[0].begin+(i<<2)))destroy_800b12f0(*(void**)((char*)range_8043bb64[0].begin+(i<<2)),3);
  *(void**)((char*)range_8043bb64[0].begin+(i<<2))=0;
 }
 if(block_804b182c){release_80209920(&heap_804adde4,block_804b182c);release_80209920(&heap_804adde4,block_804b1830);release_80209920(&heap_804adde4,block_804b1834);}
 range_8043bb64[0].clear();self->extra.clear();self->mode=0;return 0;
}
