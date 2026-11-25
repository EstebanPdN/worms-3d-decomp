#include "w3d_ptr.h"
#line 1 "cx11a_random_vector_800dd424.cpp"
// PPC32 state has three-component vectors at +0x18,+0x24,+0x30 and random-source flag at +0x6c. Names inferred.
struct Cx11aVec3 {float x,y,z;void multiply(float k){x*=k;y*=k;z*=k;}void divide(float k){x/=k;y/=k;z/=k;}};
struct Cx11aRandomState {unsigned char unknown00[0x18];Cx11aVec3 position,velocity,angles;unsigned char unknown3c[0x30];int externalRandom;};
extern unsigned int seed_804aec54;
extern "C" float random_80162bc8();
extern const float multiplier_80389ae0[],center_80389ae4[];
extern const float neutral_80389af0[];
extern const float turn_80389ae8[],half_80389aec[];
extern "C" void w3d_cx11a_random_vector_800dd424(Ptr32<Cx11aRandomState> self,Ptr32<const Cx11aVec3> base,Ptr32<const Cx11aVec3> range,int convert,float scale){
 // Observed inline arithmetic workspace precedes the unsigned conversion slot.
float r;
if(self->externalRandom)r=random_80162bc8();else{seed_804aec54=seed_804aec54*0x41c64e6d+0x3039;r=(float)seed_804aec54*multiplier_80389ae0[0];}
self->angles.x=((r-center_80389ae4[0])+(r-center_80389ae4[0]))*range->x+base->x;
if(self->externalRandom)r=random_80162bc8();else{seed_804aec54=seed_804aec54*0x41c64e6d+0x3039;r=(float)seed_804aec54*multiplier_80389ae0[0];}
self->angles.y=((r-center_80389ae4[0])+(r-center_80389ae4[0]))*range->y+base->y;
if(self->externalRandom)r=random_80162bc8();else{seed_804aec54=seed_804aec54*0x41c64e6d+0x3039;r=(float)seed_804aec54*multiplier_80389ae0[0];}
self->angles.z=((r-center_80389ae4[0])+(r-center_80389ae4[0]))*range->z+base->z;
if(convert){self->angles.x=self->angles.x*turn_80389ae8[0]/half_80389aec[0];self->angles.y=self->angles.y*turn_80389ae8[0]/half_80389aec[0];self->angles.z=self->angles.z*turn_80389ae8[0]/half_80389aec[0];}
if(scale!=neutral_80389af0[0])self->angles.multiply(scale);
}


