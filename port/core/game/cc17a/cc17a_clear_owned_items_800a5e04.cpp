#include "w3d_ptr.h"
#line 1 "cc17a_clear_owned_items_800a5e04.cpp"
// Observed PPC32 pointer-vector header and zero-length trailing move.
extern "C" void copy_802eee50(Ptr32<void>,Ptr32<const void>,...);
struct Cc17aVector{Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end; Ptr32<Ptr32<void>> capacity;Ptr32<Ptr32<void>> cc17a_end(){return end;}
 void clear(){Ptr32<Ptr32<void>> first=begin;Ptr32<Ptr32<void>> last=end;int bytes=(Ptr32<char>)last-(Ptr32<char>)first;copy_802eee50(first,last,0);end=(Ptr32<Ptr32<void>>)((Ptr32<char>)end-bytes);}
};
extern "C" void destroy_8015f558(Ptr32<void>,int),release_80209920(Ptr32<void>,Ptr32<void>);struct Cc17aHeap{unsigned state;};extern Cc17aHeap heap_804ae280;
struct Cc17aOwner{char pad[36];Cc17aVector items;int ready;};
extern "C" void w3d_cc17a_clear_owned_items_800a5e04(Ptr32<Cc17aOwner> self){*((Ptr32<char>)self+1)=0;for(Ptr32<Ptr32<void>> p=self->items.begin;p!=self->items.cc17a_end();++p){Ptr32<void> item=*p;if(item){destroy_8015f558((Ptr32<char>)item+4,2);release_80209920(&heap_804ae280,item);}}self->items.clear();self->ready=1;}


