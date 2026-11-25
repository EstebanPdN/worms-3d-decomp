#include "w3d_ptr.h"
#line 1 "cc26b_clamp_curve_801966a0.cpp"
// Original DOL frame reserves 32 bytes below the saved registers.
// Pair fields at offsets 8/12 are observed; the remaining local extent and
// original source declaration are unknown. reserved models that extent only.
// Semantic curve names are inferred. Constants reside in original read-only data.
typedef unsigned int cc26b_u32;
struct cc26b_Curve {Ptr32<cc26b_u32> key;};
extern int cc26b_global_804ab6ec;
extern const float cc26b_constant_803a84c4[],cc26b_constant_803a84c8[],cc26b_constant_803a84cc[],cc26b_constant_803a84d0[],cc26b_constant_803a84d4[];
extern float cc26b_global_804b18d0,cc26b_global_804b18d4;
extern float cc26b_global_804a91e4[],cc26b_global_804a91f4[];
extern "C" void cc26b_fn_80196668();
extern "C" void cc26b_fn_8019705c(Ptr32<cc26b_Curve>,Ptr32<float>,Ptr32<float>);
extern "C" void cc26b_fn_80197208(Ptr32<cc26b_Curve>,Ptr32<float>,Ptr32<float>,Ptr32<float>,Ptr32<float>,float,float,float,float);
extern "C" void w3d_cc26b_clamp_curve_801966a0(Ptr32<cc26b_Curve> self,Ptr32<float> x,Ptr32<float> y) {
 if(!cc26b_global_804ab6ec){cc26b_fn_80196668();cc26b_global_804ab6ec=1;}
 Ptr32<cc26b_u32> key=self->key;
 if(key) {
  float extent=x[3]-x[0];
  if(extent!=cc26b_constant_803a84c4[0]) {
   struct cc26b_Pair {float a,b;char reserved[24];} pair;
   pair.a=(x[1]-x[0])/extent;
   pair.b=(x[2]-x[0])/extent;
   if(pair.a==cc26b_constant_803a84c8[0]&&pair.b==cc26b_constant_803a84cc[0])*key|=0x10000000;
   else *self->key&=0xefffffff;
   float olda=pair.a,oldb=pair.b;
   if(olda<cc26b_constant_803a84c4[0])pair.a=cc26b_constant_803a84c4[0];
   if(oldb>cc26b_constant_803a84d0[0])pair.b=cc26b_constant_803a84d0[0];
   if(pair.a>cc26b_constant_803a84d0[0]||pair.b<cc26b_constant_803a84d4[0])cc26b_fn_8019705c(self,&pair.a,&pair.b);
   if(pair.a!=olda){x[1]=pair.a*extent+x[0];if(olda!=cc26b_constant_803a84c4[0])y[1]=y[0]+((y[1]-y[0])*pair.a)/olda;}
   if(pair.b!=oldb){x[2]=pair.b*extent+x[0];if(oldb!=cc26b_constant_803a84d0[0])y[2]=y[3]-((y[3]-y[2])*(cc26b_constant_803a84d0[0]-pair.b))/(cc26b_constant_803a84d0[0]-oldb);}
   cc26b_global_804b18d0=x[0];cc26b_global_804b18d4=x[3];
   cc26b_fn_80197208(self,cc26b_global_804a91e4,cc26b_global_804a91e4-1,cc26b_global_804a91e4-2,cc26b_global_804a91e4-3,cc26b_constant_803a84c4[0],pair.a,pair.b,cc26b_constant_803a84d0[0]);
   cc26b_fn_80197208(self,cc26b_global_804a91f4,cc26b_global_804a91f4-1,cc26b_global_804a91f4-2,cc26b_global_804a91f4-3,y[0],y[1],y[2],y[3]);
  }
 }
}


