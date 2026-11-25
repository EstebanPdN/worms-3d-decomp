// Inferred names; PPC32 pointers and words occupy four bytes; literal offsets are instruction observations.
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))

extern "C" void *move_802eeef4(void *,const void *,u32);
struct Vector{void **begin,**end,**capacity;};
static inline void shift(void **out,void **first,void **last){if(last!=first)move_802eeef4(out,first,(char *)last-(char *)first);}
extern "C" int w3d_cx15b_pointer_vector_remove_801f9f2c(Vector *self,void *value){void **cur=self->begin;if(cur!=self->end){do{if(*cur==value){void **next=cur+1,**last=self->end;if(next!=last)shift(cur,next,last);--self->end;return 0;}++cur;}while(cur!=self->end);}return (int)0x80004005;}

