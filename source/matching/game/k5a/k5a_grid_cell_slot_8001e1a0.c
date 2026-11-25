/* Layer rows start every 16 bytes inside the chunk; the cell pointer sits 100 bytes into a row. */
typedef struct K5aChunkLayer { char pad0[100]; int *cells; } K5aChunkLayer;
typedef struct K5aChunk
{
  char pad0[28];
  short x_min;
  short z_min;
  short x_max;
} K5aChunk;
typedef struct K5aWorldGrid { char pad0[108]; int fallback[1]; } K5aWorldGrid;
extern K5aChunk *FUN_8001df1c(K5aWorldGrid *self, int x, int z);

int *k5a_grid_cell_slot_8001e1a0(K5aWorldGrid *self, int x, int z, int layer)
{
  short short_x;
  short short_z_min;
  K5aChunk *chunk = FUN_8001df1c(self, x, z);
  if (chunk == 0)
    return self->fallback;
  short_x = (short)x;
  short_z_min = chunk->z_min;
  {
    K5aChunkLayer *row = (K5aChunkLayer *)((layer << 4) + (unsigned int)chunk);
    int rows = ((short)z - short_z_min) * (chunk->x_max - chunk->x_min);
    return row->cells + ((rows + short_x) - chunk->x_min);
  }
}
