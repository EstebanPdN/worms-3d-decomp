#include "w3d_ptr.h"
#line 1 "cc17a_apply_active_key_800368ac.cpp"
// Pointer-vector owner at +4; entry match word is observed at +12.
struct Cc17aEntry{char pad[12];int key;};struct Cc17aVector{Ptr32<Ptr32<Cc17aEntry>> begin; Ptr32<Ptr32<Cc17aEntry>> end; Ptr32<Ptr32<Cc17aEntry>> capacity;unsigned cc17a_size(){return end-begin;}};struct Cc17aOwner{unsigned tag;Cc17aVector items;};
extern "C" int active_80036c8c(Ptr32<Cc17aEntry>);extern "C" void apply_80036afc(Ptr32<Cc17aEntry>);
extern "C" void w3d_cc17a_apply_active_key_800368ac(Ptr32<Cc17aOwner> self,int key){for(unsigned i=0;i<self->items.cc17a_size();++i){if(active_80036c8c(*(Ptr32<Ptr32<Cc17aEntry>>)((Ptr32<char>)self->items.begin+(i<<2))) && key==(*(Ptr32<Ptr32<Cc17aEntry>>)((Ptr32<char>)self->items.begin+(i<<2)))->key){apply_80036afc(*(Ptr32<Ptr32<Cc17aEntry>>)((Ptr32<char>)self->items.begin+(i<<2)));break;}}}


