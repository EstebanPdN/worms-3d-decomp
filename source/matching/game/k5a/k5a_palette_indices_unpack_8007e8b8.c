typedef struct K5aPaletteSet
{
  char pad0[396];
  unsigned short *palette;
  char pad1[280];
  unsigned int *entries;
  char pad2[1794];
  unsigned short count;
} K5aPaletteSet;

void k5a_palette_indices_unpack_8007e8b8(K5aPaletteSet *self, unsigned short *out)
{
  unsigned int i = 0;
  if (i < self->count)
  {
    unsigned int out_off = 0;
    unsigned int in_off = 0;
    do
    {
      unsigned int entry = *(unsigned int *)(in_off + (unsigned)self->entries);
      i++;
      in_off += 4;
      *(unsigned short *)(out_off + (unsigned)out) = (self->palette[entry & 0xff] & 0xfff0) | ((entry >> 12) & 0xf);
      out_off += 2;
    } while (i < self->count);
  }
}
