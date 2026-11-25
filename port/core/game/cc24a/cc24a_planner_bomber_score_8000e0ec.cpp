#include "w3d_ptr.h"
#line 1 "cc24a_planner_bomber_score_8000e0ec.cpp"
// GWMP8P 0x8000e0ec: bomber area-score inputs and final weighted cost.
struct cc24a_BomberScore { int unknown0;float cost;char unknown8[92];float weight; };
struct cc24a_BomberConfig { char unknown0[88];float widthScale,rangeScale;char unknown96[328];float bomberScale; };
struct cc24a_BomberName { Ptr32<const char> text; };
extern Ptr32<cc24a_BomberConfig> cc24a_config_804aa6d8;
extern char cc24a_speed_name_80369f44[],cc24a_duration_name_80369f58[];
extern "C" void cc24a_reset_8000b2f8(Ptr32<cc24a_BomberScore>,int),cc24a_exposure_8000b7dc(Ptr32<cc24a_BomberScore>);
extern "C" int cc24a_float_property_800fc270(Ptr32<cc24a_BomberName>,Ptr32<float>),cc24a_uint_property_800fc230(Ptr32<cc24a_BomberName>,Ptr32<unsigned int>);
extern "C" float cc24a_damage_8000e058(Ptr32<cc24a_BomberScore>),cc24a_radius_8000e094(Ptr32<cc24a_BomberScore>),cc24a_range_8000e0bc(Ptr32<cc24a_BomberScore>);
extern "C" float cc24a_sum_8000b4c4(Ptr32<cc24a_BomberScore>,float,float,float,float),cc24a_distance_8000b5f4(Ptr32<cc24a_BomberScore>,float);
extern "C" void cc24a_planner_bomber_score_8000e0ec(Ptr32<cc24a_BomberScore> self){
 cc24a_reset_8000b2f8(self,0);
 float damage=cc24a_damage_8000e058(self);
 // Original has eight unused bytes after the property locals; source purpose unknown.
 struct cc24a_BomberWorkspace {cc24a_BomberName speedName;float speed;cc24a_BomberName durationName;unsigned int duration;unsigned char unknown[8];} work;
 work.speedName.text=cc24a_speed_name_80369f44;
 cc24a_float_property_800fc270(&work.speedName,&work.speed);
 work.durationName.text=cc24a_duration_name_80369f58;
 cc24a_uint_property_800fc230(&work.durationName,&work.duration);
 float radius=cc24a_radius_8000e094(self);
 float span=work.speed*(float)work.duration+(radius+radius);
 self->cost+=cc24a_sum_8000b4c4(self,span,cc24a_config_804aa6d8->rangeScale,cc24a_config_804aa6d8->widthScale,damage);
 self->cost+=cc24a_distance_8000b5f4(self,cc24a_range_8000e0bc(self));
 cc24a_exposure_8000b7dc(self);
 self->cost=self->cost*cc24a_config_804aa6d8->bomberScale*self->weight;
}


