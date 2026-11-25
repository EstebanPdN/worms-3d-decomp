#include "w3d_ptr.h"
#line 1 "sol35b7_motion_dispatch_800d8828.cpp"
// Inferred native GC32 views; flag width follows observed register-pair ABI.
namespace Sol35b7MotionDispatch {
struct Vec3 {float x,y,z;float lengthSquared()const{return z*z+(x*x+y*y);}};
struct Owner {char unknown0[36];Vec3 position,velocity;char unknown60[28];int armed;char unknown92[28];int active;char unknown124[68];Ptr32<void> sync;};
struct Config {char unknown0[448];int normal;char unknown452[16];int first,second;};
extern "C" {
Ptr32<void> sol35b7_sync_80341584(Ptr32<void>);
Ptr32<Config> sol35b7_config_801797b4(Ptr32<void>);
void sol35b7_refresh_800ecb20(Ptr32<Owner>);
void sol35b7_schedule_800d973c(Ptr32<Owner>,Ptr32<Vec3>,Ptr32<Vec3>,Ptr32<const Vec3>);
void sol35b7_prepare_800ec5c8(Ptr32<Owner>,int,Ptr32<Vec3>,Ptr32<Vec3>,Ptr32<const Vec3>);
void sol35b7_start_800d8b4c(Ptr32<Owner>);
void sol35b7_stop_800d8938(Ptr32<Owner>);
extern const float sol35b7_threshold_8038928c[];
}
extern "C" void sol35b7_motion_dispatch_800d8828(Ptr32<Owner> s,int a,unsigned long long flags,int reserved,Ptr32<const Vec3> normal){
 Ptr32<Config> cfg=sol35b7_config_801797b4(sol35b7_sync_80341584(s->sync));
 int mode;
 if(flags&1)mode=cfg->first;
 else if(flags&0x40000000)mode=cfg->second;
 else mode=cfg->normal;
 if(s->active)sol35b7_refresh_800ecb20(s);
 else if(s->armed&&mode)sol35b7_schedule_800d973c(s,&s->position,&s->velocity,normal);
 else {
  sol35b7_prepare_800ec5c8(s,a,&s->position,&s->velocity,normal);
  if(s->velocity.lengthSquared()>sol35b7_threshold_8038928c[0])sol35b7_start_800d8b4c(s);
  else sol35b7_stop_800d8938(s);
 }
}
}

// Both direct parameter chains consume the final argument as a three-float
// vector: schedule -> 800d8ed8 -> 800e7c78, prepare -> 800ec400 -> 800c2494.
// The empty sync accessor preserves r3 for config's +4/+28 dereferences.
// Position/velocity aliases must remain live across these external operations.
// Native floating-point rounding/NaNs and backend ownership remain external;
// exact bytes do not establish portable behavior or complete class identities.
typedef char sol35b7_motion_vec_size[(sizeof(Sol35b7MotionDispatch::Vec3)==12)?1:-1];
typedef char sol35b7_motion_owner_size[(sizeof(Sol35b7MotionDispatch::Owner)==196)?1:-1];
typedef char sol35b7_motion_config_size[(sizeof(Sol35b7MotionDispatch::Config)==476)?1:-1];


