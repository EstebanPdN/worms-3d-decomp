#include "w3d_ptr.h"
#line 1 "cc25a_planner_clear_neighborhood_80019ea0.cpp"
// Original 0x80019ea0: clear two score fields in a clipped 11-by-11 neighborhood.
// Coordinates and layer are observed signed16 and unsigned8. Names are inferred.
struct cc25a_Cell19ea0 {short unknown0,x,z;unsigned char layer,unknown7;};
struct cc25a_Score19ea0 {unsigned int unknown0;float first,second;unsigned int unknown12,unknown16;};
struct cc25a_Table19ea0 {cc25a_Score19ea0 values[16*11*11];Ptr32<cc25a_Score19ea0> get(int layer,int x,int z){return &values[(layer*11+x)*11+z];}};
extern Ptr32<cc25a_Table19ea0> cc25a_scores_804aa758;
extern Ptr32<void> cc25a_grid_804b1758;
struct cc25a_Origin19ea0{float x,y,z;};
extern cc25a_Origin19ea0 cc25a_origin_8041d3a0[];
extern const float cc25a_clear_8036a95c[];
extern "C" int cc25a_grid_coords_8001e328(Ptr32<void>,Ptr32<const cc25a_Origin19ea0>,Ptr32<short>,Ptr32<short>,Ptr32<unsigned int>);
extern "C" void cc25a_planner_clear_neighborhood_80019ea0(Ptr32<const cc25a_Cell19ea0> cell,int radius){
 short x,z;unsigned int layer;
 Ptr32<const cc25a_Origin19ea0> origin=cc25a_origin_8041d3a0;
 cc25a_grid_coords_8001e328(cc25a_grid_804b1758,origin,&x,&z,&layer);
 int dx=(cell->x-x)/2,dz=(cell->z-z)/2;
 for(int i=-radius;i<=radius;++i)for(int j=-radius;j<=radius;++j){
  int xx=dx+i,zz=dz+j;
  float clear=-1000000.0f;
  if(xx>=-5 && xx<=5 && zz>=-5 && zz<=5){
   Ptr32<cc25a_Score19ea0> score=cc25a_scores_804aa758->get(cell->layer,xx+5,zz+5);
   score->first=clear;score->second=clear;
  }
 }
}


