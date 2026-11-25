#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "cxa2_grid_storage_8002c2f8.c"
/* Observed PPC32 hierarchy storage constructor at 0x8002c2f8.
 * Dimensions round (input-1) down to an even count at each shift, then add two.
 * Use caller storage or allocate, clear all words and build coarse-to-fine offsets.
 * The leading unknown word and external allocation/lifetime policy stay unresolved. */
typedef unsigned int u32;
struct Grid {u32 offsets[5],widths[5],heights[5],magic;};
struct Owner {u32 unknown;Ptr32<struct Grid> data;u32 words,external;};
extern Ptr32<void> alloc_801fe220(u32);
extern Ptr32<void> fill_802eefe0(Ptr32<void>,int,u32);
Ptr32<struct Owner> cxa2_grid_storage_8002c2f8(Ptr32<struct Owner> self,u32 w,u32 h,Ptr32<struct Grid> storage) {
 u32 w0,w1,w2,w3,w4,h0,h1,h2,h3,h4,a0,a1,a2,a3,a4,total;
 --w;--h;
 w0=(w&~1U)+2; h0=(h&~1U)+2;
 w1=((w>>1)&~1U)+2;h1=((h>>1)&~1U)+2;
 w2=((w>>2)&~1U)+2;h2=((h>>2)&~1U)+2;
 w3=((w>>3)&~1U)+2;h3=((h>>3)&~1U)+2;
 w4=((w>>4)&~1U)+2;h4=((h>>4)&~1U)+2;
 a0=w0*h0;a1=w1*h1;a2=w2*h2;a3=w3*h3;a4=w4*h4;
 total=16+a0+a1+a2+a3+a4;
 if(storage){self->data=storage;self->external=1;}
 else {self->data=alloc_801fe220(total*4);self->external=0;}
 self->words=total;
 fill_802eefe0(self->data,0,total*4);
 self->data->offsets[4]=16;
 self->data->offsets[3]=16+a4;
 self->data->offsets[2]=self->data->offsets[3]+a3;
 self->data->offsets[1]=self->data->offsets[2]+a2;
 self->data->offsets[0]=self->data->offsets[1]+a1;
 self->data->widths[0]=w0;self->data->heights[0]=h0;
 self->data->widths[1]=w1;self->data->heights[1]=h1;
 self->data->widths[2]=w2;self->data->heights[2]=h2;
 self->data->widths[3]=w3;self->data->heights[3]=h3;
 self->data->widths[4]=w4;self->data->heights[4]=h4;
 self->data->magic=0xbaadf00d;
 return self;
}

}
