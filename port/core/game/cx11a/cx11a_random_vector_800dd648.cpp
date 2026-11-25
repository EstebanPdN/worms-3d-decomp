#include "w3d_ptr.h"
#line 1 "cx11a_random_vector_800dd648.cpp"
// PPC32 state has three-component vectors at +0x18,+0x24,+0x30 and random-source flag at +0x6c. Names inferred.
struct Cx11aVec3 {float x,y,z;void multiply(float k){x*=k;y*=k;z*=k;}void divide(float k){x/=k;y/=k;z/=k;}};
struct Cx11aRandomState {unsigned char unknown00[0x18];Cx11aVec3 position,velocity,angles;unsigned char unknown3c[0x30];int externalRandom;};
extern unsigned int seed_804aec54;
extern "C" float random_80162bc8();
extern const float multiplier_80389b00[],center_80389b04[];
extern const float turn_80389b08[],half_80389b0c[];
extern "C" void w3d_cx11a_random_vector_800dd648(Ptr32<Cx11aRandomState> self,Ptr32<const Cx11aVec3> base,Ptr32<const Cx11aVec3> range,int convert){
 // Observed inline arithmetic workspace precedes the unsigned conversion slot.
 
float r;
if(self->externalRandom)r=random_80162bc8();else{seed_804aec54=seed_804aec54*0x41c64e6d+0x3039;r=(float)seed_804aec54*multiplier_80389b00[0];}
self->velocity.x=((r-center_80389b04[0])+(r-center_80389b04[0]))*range->x+base->x;
if(self->externalRandom)r=random_80162bc8();else{seed_804aec54=seed_804aec54*0x41c64e6d+0x3039;r=(float)seed_804aec54*multiplier_80389b00[0];}
self->velocity.y=((r-center_80389b04[0])+(r-center_80389b04[0]))*range->y+base->y;
if(self->externalRandom)r=random_80162bc8();else{seed_804aec54=seed_804aec54*0x41c64e6d+0x3039;r=(float)seed_804aec54*multiplier_80389b00[0];}
self->velocity.z=((r-center_80389b04[0])+(r-center_80389b04[0]))*range->z+base->z;
if(convert){self->velocity.x=self->velocity.x*turn_80389b08[0]/half_80389b0c[0];self->velocity.y=self->velocity.y*turn_80389b08[0]/half_80389b0c[0];self->velocity.z=self->velocity.z*turn_80389b08[0]/half_80389b0c[0];}
}


