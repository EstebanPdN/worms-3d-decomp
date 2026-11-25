#include "w3d_ptr.h"
#line 1 "cc39a_worm_proximity_80107f54.cpp"
// Partial proximity sensor view; original flag words and unsigned range result.
struct cc39a_Vec3{float x,y,z;cc39a_Vec3(float a,float b,float c):x(a),y(b),z(c){}};
struct cc39a_Sensor{unsigned char unknown00[216];int nearby;unsigned char unknowndc[84];unsigned flags;};
struct cc39a_Target;
extern const char cc39a_active_80399b20[];
extern const float cc39a_zero_80399b30[],cc39a_height_80399b34[];
extern cc39a_Vec3 cc39a_runtimeVector_8045e788[]; // Runtime vector: unowned, not a file constant.
extern unsigned cc39a_distance_804b1764;
extern "C" int cc39a_property_800fc1f0(Ptr32<Ptr32<const char>>,Ptr32<int>);
extern "C" Ptr32<cc39a_Target> cc39a_target_800fc6dc(int);
extern "C" void cc39a_query_800b0824(Ptr32<cc39a_Target>,Ptr32<cc39a_Vec3>,Ptr32<cc39a_Vec3>,int,int);
extern "C" void cc39a_worm_proximity_80107f54(Ptr32<cc39a_Sensor> self,Ptr32<cc39a_Target> target){
 Ptr32<const char> key=cc39a_active_80399b20;int index;
 int status=cc39a_property_800fc1f0(&key,&index);
 if(index>=0 && status>=0){
  cc39a_target_800fc6dc(index);
  cc39a_Vec3 offset(cc39a_zero_80399b30[0],cc39a_height_80399b34[0],cc39a_zero_80399b30[0]);
  cc39a_query_800b0824(target,&offset,cc39a_runtimeVector_8045e788,600,1);
  if(cc39a_distance_804b1764<600){
   if(self->nearby!=0)return;
   self->nearby=1;self->flags=(self->flags|1)&~2u;
  }else{
   if(self->nearby!=1)return;
   self->nearby=0;self->flags|=3;
  }
 }
}


