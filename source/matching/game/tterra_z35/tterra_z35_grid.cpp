// Observed prefix views; coordinates are sign extended after the lookup.
struct Z35Chunk { unsigned char pad[28]; short xmin,zmin,xmax,zmax; };
struct Z35Grid { unsigned char pad[108]; float fallback; };
struct Z35Planes { unsigned char pad[68]; float *lower; unsigned char gap[28]; float *upper;
 float midpoint(int offset) { return (*(float *)((char *)lower+(offset<<2))+*(float *)((char *)upper+(offset<<2)))*0.5f; }
};
extern "C" Z35Chunk *z35_find_8001df1c(Z35Grid*, int, int);
extern "C" float tterra_z35_grid_8001e07c(Z35Grid *self,int x,int z,int layer) {
 Z35Chunk *chunk=z35_find_8001df1c(self,x,z);
 if(!chunk) return self->fallback;
 {
  int index=(((short)z-chunk->zmin)*(chunk->xmax-chunk->xmin)+(short)x)-chunk->xmin;
  Z35Planes *planes=(Z35Planes *)((char *)chunk+(layer<<4));
  return planes->midpoint(index);
 }
}
