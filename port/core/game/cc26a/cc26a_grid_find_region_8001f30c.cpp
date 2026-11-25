#include "w3d_ptr.h"
#line 1 "cc26a_grid_find_region_8001f30c.cpp"
// Original region lookup: strict distance threshold rejects unordered differences.
struct cc26a_VecF30c {float x,y,z;float distance2(const cc26a_VecF30c& b)const{float dx=x-b.x,dy=y-b.y,dz=z-b.z;return dx*dx+dy*dy+dz*dz;}};
struct cc26a_RegionF30c {unsigned int unknown;cc26a_VecF30c position;float radius;};
struct cc26a_GridF30c {unsigned char unknown[32];Ptr32<Ptr32<cc26a_RegionF30c>> begin; Ptr32<Ptr32<cc26a_RegionF30c>> end;};
extern "C" Ptr32<cc26a_RegionF30c> cc26a_grid_find_region_8001f30c(float radius,Ptr32<cc26a_GridF30c> self,Ptr32<const cc26a_VecF30c> point){
 Ptr32<Ptr32<cc26a_RegionF30c>> last=self->end;Ptr32<Ptr32<cc26a_RegionF30c>> cursor=self->begin;int index=0,count=last-cursor;
 for(;index<count;++index){Ptr32<cc26a_RegionF30c> entry=*cursor++;
  if(entry->position.distance2(*point)<2.0f){if(entry->radius==radius)return entry;}
 }
 return 0;
}


