#include "w3d_ptr.h"
#line 1 "sol35b5_explosion_800eca14.cpp"
// Inferred GC32 partial layouts and descriptive names.
struct Vec3 {float x,y,z;};
struct Motion {char unknown0[192];Ptr32<void> sync;};
struct Config {char unknown0[200];float damage;char unknown204[40];float offset,impulseRadius,landRadius;char unknown256[4];float damageRadius,impulse;char unknown268[48];unsigned count;};
extern "C" {
Ptr32<void> sol35b5_sync_80341584(Ptr32<void>);
Ptr32<Config> sol35b5_config_801797b4(Ptr32<void>);
unsigned sol35b5_random_80161080(Ptr32<Motion>);
Ptr32<void> sol35b5_allocate_801613f0(Ptr32<void>,unsigned);
Ptr32<void> sol35b5_construct_800666b4(Ptr32<void>,Ptr32<const Vec3>,Ptr32<const Vec3>,float,float,float,float,float);
int sol35b5_post_8016239c(Ptr32<void>);
}
extern Ptr32<void> sol35b5_arena_804b1754;
extern "C" void sol35b5_explosion_800eca14(Ptr32<Motion> s,const Vec3 &position){
 Ptr32<Config> cfg=sol35b5_config_801797b4(sol35b5_sync_80341584(s->sync));
 float offset=cfg->offset;
 Vec3 center=position;
 Vec3 impulse=center;
 impulse.y+=offset;
 unsigned count=1;
 if(cfg->count) count=sol35b5_random_80161080(s)%cfg->count+1;
 Ptr32<void> storage=sol35b5_allocate_801613f0(sol35b5_arena_804b1754,52);
 float scale=float(count);
 sol35b5_post_8016239c(sol35b5_construct_800666b4(storage,&center,&impulse,cfg->damage*scale,cfg->impulse*scale,cfg->damageRadius*scale,cfg->landRadius*scale,cfg->impulseRadius*scale));
}

// The empty accessor preserves its incoming r3; the next native function reads
// +4 through that value and then +28 through the resulting pointer. Pointer
// identity return is inferred from this observed consuming boundary.
// The random call may mutate cfg->count, which is deliberately reloaded after
// it returns. A resulting zero divisor is outside defined C++ semantics.
// Native floating rounding and external allocator/message ownership are limits.
typedef char sol35b5_vec_size[(sizeof(Vec3)==12)?1:-1];
typedef char sol35b5_motion_size[(sizeof(Motion)==196)?1:-1];
typedef char sol35b5_config_size[(sizeof(Config)==320)?1:-1];


