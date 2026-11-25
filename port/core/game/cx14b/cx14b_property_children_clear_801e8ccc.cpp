#include "w3d_ptr.h"
#line 1 "cx14b_property_children_clear_801e8ccc.cpp"

// PPC32: child vector +48, cached string table +72; each child is a four-byte pointer.
struct Vector{Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end; Ptr32<Ptr32<void>> capacity;};struct Owner{char pad[48];Vector children;char gap[12];Ptr32<void> cache;};
extern "C" void child_801eb074(Ptr32<void>,int);extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,...);extern "C" void cache_8020cb38(Ptr32<void>,int);
inline void clear(Ptr32<Vector> v){Ptr32<Ptr32<void>> begin=v->begin; Ptr32<Ptr32<void>> end=v->end;unsigned bytes=(unsigned)w3d::H(end)-(unsigned)w3d::H(begin);copy_802eee50(begin,end,0);v->end=(Ptr32<Ptr32<void>>)w3d::G(((unsigned)w3d::H(v->end)-bytes));}
extern "C" void w3d_cx14b_property_children_clear_801e8ccc(Ptr32<Owner> self){Ptr32<Ptr32<void>> p=self->children.begin; Ptr32<Ptr32<void>> end=self->children.end;if(p!=end)do{if(*p)child_801eb074(*p,3);++p;}while(p!=end);clear(&self->children);if(self->cache)cache_8020cb38(self->cache,3);self->cache=0;}



