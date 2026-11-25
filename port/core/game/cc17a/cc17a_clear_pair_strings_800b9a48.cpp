#include "w3d_ptr.h"
#line 1 "cc17a_clear_pair_strings_800b9a48.cpp"
// Observed PPC32 pointer-vector header and zero-length trailing move.
extern "C" void copy_802eee50(Ptr32<void>,Ptr32<const void>,...);
struct Cc17aVector{Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end; Ptr32<Ptr32<void>> capacity;unsigned cc17a_size(){return end-begin;}
 void clear(){Ptr32<Ptr32<void>> first=begin;Ptr32<Ptr32<void>> last=end;int bytes=(Ptr32<char>)last-(Ptr32<char>)first;copy_802eee50(first,last,0);end=(Ptr32<Ptr32<void>>)((Ptr32<char>)end-bytes);}
};
extern "C" void destroy_800b916c(Ptr32<void>,int);
struct Cc17aOwner{char pad[52];Cc17aVector items;};
extern "C" int w3d_cc17a_clear_pair_strings_800b9a48(Ptr32<Cc17aOwner> self){for(unsigned i=0;i<self->items.cc17a_size();++i){Ptr32<void> item=*(Ptr32<Ptr32<void>>)((Ptr32<char>)self->items.begin+(i<<2));if(item)destroy_800b916c(item,3);*(Ptr32<Ptr32<void>>)((Ptr32<char>)self->items.begin+(i<<2))=0;}self->items.clear();return 0;}


