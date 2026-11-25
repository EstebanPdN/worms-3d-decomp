// Inferred names; observed PPC32 pointers/words are four bytes. Offsets follow original instructions.
typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8;
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))

extern "C" { extern void *pending_804a8bd8[]; extern void *enabled_804a8dd8[]; extern void *owned_804a89d8[]; }
extern "C" int w3d_cx15b_pool_pending_dispatch_8017d3bc(void *self) {
 int result=0; u8 category=0;
 do { u32 index=category; if(pending_804a8bd8[index] && enabled_804a8dd8[index] && !owned_804a89d8[index]) {
 int r=((int (*)(void *,u8 *))FIELD(FIELD(self,void *,0),void *,64))(self,&category); if(r<0)result=r;
 } ++category; }while(!(category&128)); return result;
}

