#include "w3d_ptr.h"
#line 1 "cc24a_planner_proximity_score_80017b80.cpp"
// GWMP8P 0x80017b80: distance-scaled plan weight. Names inferred.
struct cc24a_ProximityVec {float x,y,z;float distance2(const cc24a_ProximityVec &other){float a=x-other.x,b=y-other.y,c=z-other.z;return c*c+(a*a+b*b);}};
struct cc24a_ProximityPlan {int unknown0;float cost;char unknown8[8];cc24a_ProximityVec origin;};
struct cc24a_ProximityConfig {char unknown0[192];float first;char unknown196[4];float second;};
extern "C" {extern Ptr32<cc24a_ProximityConfig> cc24a_config_804aa6d8;extern int cc24a_owner_804aa6c0;extern cc24a_ProximityVec cc24a_origin_8041d3a0[];extern float cc24a_threshold_8036a82c[];
 void cc24a_reset_80017a04(Ptr32<cc24a_ProximityPlan>);float cc24a_factor_80019fb4(Ptr32<cc24a_ProximityVec>,int,float,float);float cc24a_sqrt_802e82c0(float);
}
extern "C" void cc24a_planner_proximity_score_80017b80(Ptr32<cc24a_ProximityPlan> self){
 cc24a_reset_80017a04(self);
 self->cost*=cc24a_factor_80019fb4(&self->origin,cc24a_owner_804aa6c0,cc24a_config_804aa6d8->first,cc24a_config_804aa6d8->second);
 float distance=cc24a_sqrt_802e82c0(cc24a_origin_8041d3a0[0].distance2(self->origin));
 float threshold=200.0f;
 if(distance<threshold)self->cost*=distance/threshold;
}


