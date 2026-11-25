// Original grid byte-cell lookup. Row view is strided by16, not a complete allocation layout.
struct cc26a_ChunkDff8 {unsigned char unknown[28];short xmin,zmin,xmax,zmax;};
struct cc26a_RowDff8 {unsigned char unknown[36];unsigned char *cells;};
struct cc26a_GridDff8;
extern "C" cc26a_ChunkDff8 *cc26a_find_8001df1c(cc26a_GridDff8*,int,int);
extern unsigned char cc26a_fallback_804ac914;
extern "C" unsigned char *cc26a_grid_byte_cell_8001dff8(cc26a_GridDff8 *self,int x,int z,int layer){
 cc26a_ChunkDff8 *chunk=cc26a_find_8001df1c(self,x,z);
 if(!chunk){cc26a_fallback_804ac914=1;return &cc26a_fallback_804ac914;}
 {
  cc26a_RowDff8 *row=(cc26a_RowDff8*)((layer<<4)+(unsigned int)chunk);
  int rows=((short)z-chunk->zmin)*(chunk->xmax-chunk->xmin);
  return row->cells+((rows+(short)x)-chunk->xmin);
 }
}
