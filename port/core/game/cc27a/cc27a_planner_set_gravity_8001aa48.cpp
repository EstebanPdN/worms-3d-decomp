#include "w3d_ptr.h"
#line 1 "cc27a_planner_set_gravity_8001aa48.cpp"
// Reset ballistic gravity from the original property and bind the original origin.
struct cc27a_VecAA48 {float x,y,z;void init(float f){x=f;y=f;z=f;}};
extern "C" void cc27a_mode_8001a758(int);
extern "C" void cc27a_origin_8001a770(Ptr32<void>,int);
extern "C" int cc27a_property_800fc270(Ptr32<Ptr32<const char>>,Ptr32<float>);
extern "C" void cc27a_set_80118230(Ptr32<void>,Ptr32<const void>);
extern "C" void cc27a_gravity_80118288(Ptr32<void>,Ptr32<const cc27a_VecAA48>);
extern char cc27a_motion_8041e780[],cc27a_origin_8041e844[],cc27a_name_8036af74[];
extern float cc27a_scale_804b1770,cc27a_time_804b1774;
extern "C" void cc27a_planner_set_gravity_8001aa48(Ptr32<void> self){
 struct {cc27a_VecAA48 vector;unsigned int unknown20;Ptr32<const char> name;float gravity;char unknown[8];} w;
 cc27a_mode_8001a758(0);cc27a_origin_8001a770(self,0);
 cc27a_scale_804b1770=0.5f;cc27a_time_804b1774=0.0f;
 w.name=cc27a_name_8036af74;w.gravity=0.0f;
 cc27a_property_800fc270(&w.name,&w.gravity);
 w.vector.init(0.0f);w.vector.y=w.gravity;
 cc27a_set_80118230(cc27a_motion_8041e780,cc27a_origin_8041e844);
 cc27a_gravity_80118288(cc27a_motion_8041e780,&w.vector);
}

