#include "w3d_ptr.h"
#line 1 "cx15b_component_vectors_destroy_801fa11c.cpp"
// Inferred names; explicit PPC32 field offsets and four-byte pointer layout follow the original DOL.
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))

extern "C" {extern char table_80418470[],derived_80418268[],base_80418328[];void release_802134fc(Ptr32<void>);void tables_8035a244(Ptr32<void>,int);void node_80210990(Ptr32<void>,int);void delete_801fe1f8(Ptr32<void>);}
struct Record{u32 words[6];};struct Vector{Ptr32<Record> begin; Ptr32<Record> end;u32 word;};
static inline void drain(Ptr32<Vector> v){Ptr32<Record> p=v->begin;while(p!=v->end)++p;if(v->begin)release_802134fc(v->begin);}
extern "C" void w3d_cx15b_component_vectors_destroy_801fa11c(Ptr32<void> self,u32 flags){FIELD(self,void *,28)=table_80418470;FIELD(self,void *,0)=derived_80418268;
 if(FIELD(self,void *,240))release_802134fc(FIELD(self,void *,240));if(FIELD(self,void *,224))release_802134fc(FIELD(self,void *,224));if(FIELD(self,void *,208))release_802134fc(FIELD(self,void *,208));if(FIELD(self,void *,112))release_802134fc(FIELD(self,void *,112));drain((Ptr32<Vector>)((Ptr32<char>)self+96));tables_8035a244((Ptr32<char>)self+28,0);FIELD(self,void *,0)=base_80418328;node_80210990((Ptr32<char>)self+12,0);if(flags&1)delete_801fe1f8(self);}



