#include "w3d_ptr.h"
#line 1 "cc24a_planner_bomber_probe_8000a9ac.cpp"
// GWMP8P 0x8000a9ac: bomber feasibility probe. Names describe inferred roles.
struct cc24a_BomberProbeVec {float x,y,z;float distance2(const cc24a_BomberProbeVec &other)const{float a=x-other.x,b=y-other.y,c=z-other.z;return c*c+(a*a+b*b);}};
struct cc24a_BomberProbePlan {char unknown0[20];int owner;cc24a_BomberProbeVec origin;char unknown36[12];cc24a_BomberProbeVec direction;char unknown60[4];unsigned char flag;bool flagged(){return flag!=0;}};
struct cc24a_BomberProbeInfo {char unknown0[500];int enabled;};
struct cc24a_BomberProbeResult {float words[3];};
extern "C" {extern cc24a_BomberProbeVec cc24a_target_8041e85c[];extern float cc24a_threshold_80369be4[];
 Ptr32<cc24a_BomberProbeInfo> cc24a_lookup_80341694(Ptr32<cc24a_BomberProbePlan>,int);
 Ptr32<void> cc24a_prepare_8002f098(Ptr32<cc24a_BomberProbeResult>,Ptr32<cc24a_BomberProbeInfo>,Ptr32<const cc24a_BomberProbeVec>,Ptr32<const cc24a_BomberProbeVec>);
 void cc24a_apply_8001a7f8(int,Ptr32<cc24a_BomberProbeResult>,int);
 Ptr32<void> cc24a_velocity_8002f2d8(Ptr32<cc24a_BomberProbeResult>,Ptr32<const cc24a_BomberProbeVec>);
 int cc24a_probe_8001b8f0(Ptr32<cc24a_BomberProbeResult>,float);
}
extern "C" int cc24a_planner_bomber_probe_8000a9ac(Ptr32<cc24a_BomberProbePlan> self){
 Ptr32<cc24a_BomberProbeInfo> info=cc24a_lookup_80341694(self,0);
 if(info->enabled && !self->flagged()){
  // Original reserves16 bytes per result; fourth word purpose unknown.
  struct cc24a_BomberProbeWorkspace {cc24a_BomberProbeResult first;unsigned int unknownFirst;cc24a_BomberProbeResult second;unsigned int unknownSecond;} work;
  cc24a_prepare_8002f098(&work.first,info,&self->origin,&self->direction);
  cc24a_apply_8001a7f8(self->owner,&work.first,0);
  cc24a_velocity_8002f2d8(&work.second,&self->direction);
  cc24a_probe_8001b8f0(&work.second,self->origin.y);
  if(cc24a_target_8041e85c[0].distance2(self->origin)>cc24a_threshold_80369be4[0])return 0;
 }
 return 1;
}


