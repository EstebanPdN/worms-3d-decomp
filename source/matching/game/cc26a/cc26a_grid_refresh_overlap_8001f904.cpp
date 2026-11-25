// Original overlap activation refresh. Original ordered <= rejects unordered distance.
struct cc26a_VecF904 {float x,y,z;float distance2(const cc26a_VecF904& b)const{float dx=x-b.x,dy=y-b.y,dz=z-b.z;return dx*dx+dy*dy+dz*dz;}};
struct cc26a_RegionF904 {unsigned int unknown;cc26a_VecF904 position;float radius;int active;};
struct cc26a_GridF904 {unsigned char unknown[32];cc26a_RegionF904 **begin,**end;};
extern "C" void cc26a_remove_8001f6fc(cc26a_GridF904*,cc26a_RegionF904*);
extern "C" void cc26a_apply_8001f4f4(cc26a_GridF904*,cc26a_RegionF904*);
extern "C" void cc26a_grid_refresh_overlap_8001f904(cc26a_GridF904 *self,cc26a_RegionF904 *region){
 if(region->active){
  cc26a_remove_8001f6fc(self,region);
  const cc26a_VecF904& center=region->position;float radius=region->radius;
  int count=self->end-self->begin;
  for(int i=0;i<count;++i){cc26a_RegionF904 *other=*(cc26a_RegionF904**)((unsigned char*)self->begin+(i<<2));
   if(other->active){float sum=radius+other->radius;
    if(other->position.distance2(center)<=sum*sum){other->active=0;cc26a_apply_8001f4f4(self,other);}
   }
  }
 }
}
