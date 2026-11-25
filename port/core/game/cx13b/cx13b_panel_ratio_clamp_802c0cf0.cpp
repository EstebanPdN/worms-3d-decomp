#include "w3d_ptr.h"
#line 1 "cx13b_panel_ratio_clamp_802c0cf0.cpp"

// PPC32 third integer argument references context data at +24; float registers are separate.
struct Context{unsigned char opaque[24];};extern "C" Ptr32<void> lookup_8015ae3c(Ptr32<void>);extern "C" Ptr32<void> view_8034435c(Ptr32<void>);extern "C" float measure_8018b4cc(Ptr32<void>,Ptr32<void>);extern "C" const float factor_803d847c[],minimum_803d8480[];
extern "C" float w3d_cx13b_panel_ratio_clamp_802c0cf0(Ptr32<void>,Ptr32<void> value,Ptr32<Context> context,float scale,float maximum){Ptr32<void> p=view_8034435c(lookup_8015ae3c((Ptr32<unsigned char>)context+24));scale*=factor_803d847c[0];float amount=measure_8018b4cc(p,value);if(scale<amount)return minimum_803d8480[0];float ratio=scale/amount;if(ratio>maximum)ratio=maximum;if(ratio<minimum_803d8480[0])ratio=minimum_803d8480[0];return ratio;}




