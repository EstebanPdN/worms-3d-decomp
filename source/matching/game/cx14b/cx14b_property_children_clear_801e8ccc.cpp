
// PPC32: child vector +48, cached string table +72; each child is a four-byte pointer.
struct Vector{void**begin,**end,**capacity;};struct Owner{char pad[48];Vector children;char gap[12];void*cache;};
extern "C" void child_801eb074(void*,int);extern "C" void*copy_802eee50(void*,const void*,...);extern "C" void cache_8020cb38(void*,int);
inline void clear(Vector*v){void**begin=v->begin,**end=v->end;unsigned bytes=(unsigned)end-(unsigned)begin;copy_802eee50(begin,end,0);v->end=(void**)((unsigned)v->end-bytes);}
extern "C" void w3d_cx14b_property_children_clear_801e8ccc(Owner*self){void**p=self->children.begin,**end=self->children.end;if(p!=end)do{if(*p)child_801eb074(*p,3);++p;}while(p!=end);clear(&self->children);if(self->cache)cache_8020cb38(self->cache,3);self->cache=0;}

