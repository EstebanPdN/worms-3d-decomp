#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "cxa2_grid_test_8002c73c.c"
/* PPC32 hierarchical bit test observed at 0x8002c73c.
 * Structural names are inferred; external scratch words remain original data.
 * Intermediate levels return true for bit 1, false when bit 0 is clear;
 * otherwise descend and test the selected bit in level zero.
 * Shift/division/bounds behavior follows the original without extra checks. */
typedef unsigned int u32;
extern u32 masks_80372724[];
extern u32 x_804accc0,z_804accc4,bit_804accc8,word_804acccc;
struct Grid {u32 offsets[5];u32 widths[5];u32 heights[5];};
int cxa2_grid_test_8002c73c(Ptr32<struct Grid> self,u32 x,u32 bit,u32 z,u32 level) {
 if(x>=self->widths[0] || z>=self->heights[0])return 0;
 if(level) {
  do {
   u32 zz=z>>level,xx=x>>level;
   u32 b=bit&masks_80372724[level];
   x_804accc0=xx;z_804accc4=zz;bit_804accc8=b;
   word_804acccc=((Ptr32<u32>)self)[self->offsets[level]+xx+zz*self->widths[level]]>>b;
   if(word_804acccc&2)return 1;
   if(!(word_804acccc&1))return 0;
   --level;
  }while(level);
 }
 word_804acccc=((Ptr32<u32>)self)[self->offsets[0]+x+z*self->widths[0]];
 return (word_804acccc&(1U<<bit))!=0;
}

}
