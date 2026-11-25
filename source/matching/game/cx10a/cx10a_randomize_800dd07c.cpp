// PPC32 observed randomized state fields at +0x44 through +0x6c; names are inferred.
struct Cx10aRandomState {unsigned char unknown00[0x44];float pairA[2],pairB[2],valueA,valueB;int countA,period;unsigned int started;unsigned char unknown68[4];int externalRandom;};
extern unsigned int seed_804aec54;
extern "C" float random_80162bc8();
extern const float multiplier_80389a98[],center_80389a9c[];
extern const float zero_80389a88[];
extern "C" void w3d_cx10a_randomize_800dd07c(Cx10aRandomState *self,const float *input,float range){
if(input[0]==zero_80389a88[0]){self->pairB[0]=zero_80389a88[0];self->pairB[1]=zero_80389a88[0];return;}
float r;if(self->externalRandom)r=random_80162bc8();else{seed_804aec54=seed_804aec54*0x41c64e6d+0x3039;r=(float)seed_804aec54*multiplier_80389a98[0];}
float delta=((r-center_80389a9c[0])+(r-center_80389a9c[0]))*range;self->pairB[0]=input[0]+delta;self->pairB[1]=input[1]+delta;
}
