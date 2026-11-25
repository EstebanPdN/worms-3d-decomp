// Inferred names; PPC32 pointers and words occupy four bytes; literal offsets are instruction observations.
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))

extern "C" void *clear_802eefe0(void *,int,u32);
struct Slots{int count;u32 word;void **items;};
extern "C" void w3d_cx15b_interface_range_remove_801f2a30(Slots *self,void **first,void **last){
 void **end=self->items+self->count;int removed=last-first;
 if(removed>0){void **cur=first;int left=removed;do{void *item=*cur++;if(item)((int (*)(void *))FIELD(FIELD(item,void *,0),void *,16))(item);}while(--left);}
 u32 trailing=(end-last);u32 i=0;void **source=first+removed;
 if(i<trailing){u32 offset=0;do{*(void **)(offset+(u32)first)=*(void **)(offset+(u32)source);offset+=4;++i;}while(i<trailing);}
 clear_802eefe0(first+trailing,0,removed*4);self->count-=removed;
}

