/* Layer rows start every 16 bytes inside the chunk; the cell pointer sits 68 bytes into a row. */
typedef struct Cc18aChunkLayer { char pad0[68]; int *cells; } Cc18aChunkLayer;
typedef struct Cc18aChunk
{
  char pad0[28];
  short x_min;
  short z_min;
  short x_max;
} Cc18aChunk;
typedef struct Cc18aWorldGrid { char pad0[108]; int fallback[1]; } Cc18aWorldGrid;
extern "C" Cc18aChunk *FUN_8001df1c(Cc18aWorldGrid *self, int x, int z);

extern "C" int *w3d_cc18a_grid_cell_slot_8001e11c(Cc18aWorldGrid *self, int x, int z, int layer)
{
  short short_x;
  short short_z_min;
  Cc18aChunk *chunk = FUN_8001df1c(self, x, z);
  if (chunk == 0)
    return self->fallback;
  short_x = (short)x;
  short_z_min = chunk->z_min;
  {
    Cc18aChunkLayer *row = (Cc18aChunkLayer *)((layer << 4) + (unsigned int)chunk);
    int rows = ((short)z - short_z_min) * (chunk->x_max - chunk->x_min);
    return row->cells + ((rows + short_x) - chunk->x_min);
  }
}
