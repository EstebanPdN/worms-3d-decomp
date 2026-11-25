#include "w3d_ptr.h"
#line 1 "cx10a_randomize_800dd998.cpp"
// PPC32 observed randomized state fields at +0x44 through +0x6c; names are inferred.
struct Cx10aRandomState {unsigned char unknown00[0x44];float pairA[2],pairB[2],valueA,valueB;int countA,period;unsigned int started;unsigned char unknown68[4];int externalRandom;};
extern unsigned int seed_804aec54;
extern "C" float random_80162bc8();
extern const float multiplier_80389b38[],center_80389b3c[];
extern "C" void w3d_cx10a_randomize_800dd998(Ptr32<Cx10aRandomState> self,float base,float range){
float r;if(self->externalRandom)r=random_80162bc8();else{seed_804aec54=seed_804aec54*0x41c64e6d+0x3039;r=(float)seed_804aec54*multiplier_80389b38[0];}
float d=r-center_80389b3c[0];self->valueA=(d+d)*range+base;
}


