#include "w3d_ptr.h"
#line 1 "cx15b_pointer_vector_remove_801f9f2c.cpp"
// Inferred names; PPC32 pointers and words occupy four bytes; literal offsets are instruction observations.
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))

extern "C" Ptr32<void> move_802eeef4(Ptr32<void>,Ptr32<const void>,u32);
struct Vector{Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end; Ptr32<Ptr32<void>> capacity;};
static inline void shift(Ptr32<Ptr32<void>> out,Ptr32<Ptr32<void>> first,Ptr32<Ptr32<void>> last){if(last!=first)move_802eeef4(out,first,(Ptr32<char>)last-(Ptr32<char>)first);}
extern "C" int w3d_cx15b_pointer_vector_remove_801f9f2c(Ptr32<Vector> self,Ptr32<void> value){Ptr32<Ptr32<void>> cur=self->begin;if(cur!=self->end){do{if(*cur==value){Ptr32<Ptr32<void>> next=cur+1; Ptr32<Ptr32<void>> last=self->end;if(next!=last)shift(cur,next,last);--self->end;return 0;}++cur;}while(cur!=self->end);}return (int)0x80004005;}



