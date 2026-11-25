#include "w3d_ptr.h"
#line 1 "cx15b_interface_range_remove_801f2a30.cpp"
// Inferred names; PPC32 pointers and words occupy four bytes; literal offsets are instruction observations.
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))

extern "C" Ptr32<void> clear_802eefe0(Ptr32<void>,int,u32);
struct Slots{int count;u32 word;Ptr32<Ptr32<void>> items;};
extern "C" void w3d_cx15b_interface_range_remove_801f2a30(Ptr32<Slots> self,Ptr32<Ptr32<void>> first,Ptr32<Ptr32<void>> last){
 Ptr32<Ptr32<void>> end=self->items+self->count;int removed=last-first;
 if(removed>0){Ptr32<Ptr32<void>> cur=first;int left=removed;do{Ptr32<void> item=*cur++;if(item)((int (*)(void *))FIELD(FIELD(item,void *,0),void *,16))(item);}while(--left);}
 u32 trailing=(end-last);u32 i=0;Ptr32<Ptr32<void>> source=first+removed;
 if(i<trailing){u32 offset=0;do{*(Ptr32<Ptr32<void>>)w3d::G((offset+(u32)w3d::H(first)))=*(Ptr32<Ptr32<void>>)w3d::G((offset+(u32)w3d::H(source)));offset+=4;++i;}while(i<trailing);}
 clear_802eefe0(first+trailing,0,removed*4);self->count-=removed;
}



