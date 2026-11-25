// PPC32 observed randomized state fields at +0x44 through +0x6c; names are inferred.
struct Cx10aRandomState {unsigned char unknown00[0x44];float pairA[2],pairB[2],valueA,valueB;int countA,period;unsigned int started;unsigned char unknown68[4];int externalRandom;};
extern unsigned int seed_804aec54;
extern "C" float random_80162bc8();
extern const float multiplier_80389b48[],center_80389b4c[];
extern const float neutral_80389b50[];
extern "C" void w3d_cx10a_randomize_800dda48(Cx10aRandomState *self,float base,float range,float scale){
float r;if(self->externalRandom)r=random_80162bc8();else{seed_804aec54=seed_804aec54*0x41c64e6d+0x3039;r=(float)seed_804aec54*multiplier_80389b48[0];}
float d=r-center_80389b4c[0];self->valueB=(d+d)*range+base;if(scale!=neutral_80389b50[0])self->valueB*=scale;
}
