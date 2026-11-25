#include "w3d_ptr.h"
#line 1 "sol35b11_jetpack_update_800adcb4.cpp"
// Original GWMP8P rev0 0x800adcb4. Inferred partial GC32 views and names.
// Update active or stopping jetpack controls, vectors, scale and effects.
// A missing handle resets channels and clears both outputs from one value.
// Scale is read anew after callbacks, matching the original reload boundary.
// Externals are address witnesses, not owned storage or recovered interfaces.
// Helpers receive the full native owner; the 84-byte view only names fields
// accessed here. Control/owner lifetimes must survive every external callback.
// Exact linking does not establish portable or whole-game execution behavior.
namespace sol35b11_jetpack {
struct Vec3 {float x,y,z;};
struct Owner {char u0[28];unsigned handle;char u32[44];float left,right;};
struct Control {char u0[72];int both;char u76[12];Vec3 first,second;char u112[20];Vec3 direction;int mode,one;char u152[8];float scale;int stopping,active;};
extern "C" {
Ptr32<Control> sol35b11_jetpack_lookup_80164fc8(unsigned);
void sol35b11_jetpack_reset_800ae220(Ptr32<Owner>);
void sol35b11_jetpack_intensity_800aee34(Ptr32<Owner>,int,int,int);
void sol35b11_jetpack_modes_800ae29c(Ptr32<Owner>,int,int);
void sol35b11_jetpack_vectors_800ae338(Ptr32<Owner>,int,int,Ptr32<const Vec3>,Ptr32<const Vec3>);
void sol35b11_jetpack_scale_800ae6d8(Ptr32<Owner>,float);
void sol35b11_jetpack_control_800ae9bc(Ptr32<Owner>,Ptr32<Control>);
void sol35b11_jetpack_effects_800ae9d0(Ptr32<Owner>,int,int,Ptr32<const Vec3>);
void sol35b11_jetpack_direction_800aec68(Ptr32<Owner>,Ptr32<const Vec3>,float);
extern float sol35b11_jetpack_zero_803820f8[],sol35b11_jetpack_one_803820fc[];
}
extern "C" int sol35b11_jetpack_update_800adcb4(Ptr32<Owner> s,int elapsed){
 Ptr32<Control> c=sol35b11_jetpack_lookup_80164fc8(s->handle);
 if(!c){sol35b11_jetpack_reset_800ae220(s);s->right=s->left=sol35b11_jetpack_zero_803820f8[0];return 0;}
 if(c->active){
  sol35b11_jetpack_intensity_800aee34(s,c->both,c->one,elapsed);
  sol35b11_jetpack_modes_800ae29c(s,c->both,c->one);
  sol35b11_jetpack_vectors_800ae338(s,c->both,c->mode,&c->first,&c->second);
  sol35b11_jetpack_scale_800ae6d8(s,c->scale);
  sol35b11_jetpack_control_800ae9bc(s,c);
  sol35b11_jetpack_effects_800ae9d0(s,c->both,c->one,&c->direction);
  sol35b11_jetpack_direction_800aec68(s,&c->direction,c->scale);
 }else if(c->stopping){
  sol35b11_jetpack_intensity_800aee34(s,0,0,elapsed);
  sol35b11_jetpack_modes_800ae29c(s,0,0);
  sol35b11_jetpack_vectors_800ae338(s,0,0,&c->first,&c->second);
  sol35b11_jetpack_scale_800ae6d8(s,sol35b11_jetpack_one_803820fc[0]);
  sol35b11_jetpack_control_800ae9bc(s,c);
  sol35b11_jetpack_effects_800ae9d0(s,0,0,&c->direction);
  sol35b11_jetpack_direction_800aec68(s,&c->direction,sol35b11_jetpack_one_803820fc[0]);
 }
 return 0;
}
}

typedef char sol35b11_jetpack_vec_size[(sizeof(sol35b11_jetpack::Vec3)==12)?1:-1];
typedef char sol35b11_jetpack_owner_view_size[(sizeof(sol35b11_jetpack::Owner)==84)?1:-1];
typedef char sol35b11_jetpack_control_view_size[(sizeof(sol35b11_jetpack::Control)==172)?1:-1];


