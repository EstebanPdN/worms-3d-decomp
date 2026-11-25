#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5a_palette_indices_unpack_8007e8b8.c"
typedef struct K5aPaletteSet
{
  char pad0[396];
  Ptr32<unsigned short> palette;
  char pad1[280];
  Ptr32<unsigned int> entries;
  char pad2[1794];
  unsigned short count;
} K5aPaletteSet;

void k5a_palette_indices_unpack_8007e8b8(Ptr32<K5aPaletteSet> self, Ptr32<unsigned short> out)
{
  unsigned int i = 0;
  if (i < self->count)
  {
    unsigned int out_off = 0;
    unsigned int in_off = 0;
    do
    {
      unsigned int entry = *(Ptr32<unsigned int>)w3d::G((in_off + (unsigned)w3d::H(self->entries)));
      i++;
      in_off += 4;
      *(Ptr32<unsigned short>)w3d::G((out_off + (unsigned)w3d::H(out))) = (self->palette[entry & 0xff] & 0xfff0) | ((entry >> 12) & 0xf);
      out_off += 2;
    } while (i < self->count);
  }
}

}
