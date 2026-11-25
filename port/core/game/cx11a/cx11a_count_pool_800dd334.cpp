#include "w3d_ptr.h"
#line 1 "cx11a_count_pool_800dd334.cpp"
// The original conversion pool contains the float LCG multiplier between unsigned and signed conversion constants.
// PPC32 observed randomized state fields at +0x44 through +0x6c; names are inferred.
struct Cx11aRandomState {unsigned char unknown00[0x44];float pairA[2],pairB[2],valueA,valueB;int countA,period;unsigned int started;unsigned char unknown68[4];int externalRandom;};
extern unsigned int seed_804aec54;
extern "C" float random_80162bc8();
extern const float center_80389ad0[];
extern "C" void w3d_cx11a_count_pool_800dd334(Ptr32<Cx11aRandomState> self,int base,int range){
float r;if(self->externalRandom)r=random_80162bc8();else{seed_804aec54=seed_804aec54*0x41c64e6d+0x3039;r=(float)seed_804aec54*2.3283064365386963e-10f;}
float b=(float)base,q=(float)range;float d=r-center_80389ad0[0];self->countA=(int)((d+d)*q+b);
}


