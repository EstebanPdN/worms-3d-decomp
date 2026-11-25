#include "w3d_ptr.h"
#line 1 "reset_motion_800d2f64.cpp"
// GC32 inferred motion fields; no claim of a portable class layout.
struct Sol31aResetVec {float x,y,z; void set(float a,float b,float c){x=a;y=b;z=c;} void add(const Sol31aResetVec &v){x+=v.x;y+=v.y;z+=v.z;}};
struct Sol31aResetParameters {unsigned char unknown0[80];float initialHeight;unsigned char unknown84[8];float rate,height;unsigned char unknown100[28];float angle;unsigned char unknown132[4];unsigned flags;};
struct Sol31aResetMotion {unsigned char unknown0[72];Ptr32<Ptr32<void>> table;unsigned char unknown76[12];Sol31aResetVec position,direction,velocity,acceleration;Ptr32<void> handle;Sol31aResetVec origin;unsigned char unknown152[4];float angle;unsigned char unknown160[16];float outputAngle,outputHeight,initialHeight,rate,otherRate;unsigned flags;};
extern "C" Ptr32<void> lookup_80341584(Ptr32<void>);
extern "C" Ptr32<Sol31aResetParameters> parameters_801797b4(Ptr32<void>);
extern "C" int test_800d4b90(Ptr32<Sol31aResetMotion>,Ptr32<float>,Ptr32<float>);
extern "C" void sol31a_reset_motion_800d2f64(Ptr32<Sol31aResetMotion> self){
 Ptr32<Sol31aResetParameters> p=parameters_801797b4(lookup_80341584(self->handle));
 typedef Ptr32<void (Ptr32<Sol31aResetMotion>, float)> SetTime;
 ((SetTime)self->table[8])(self,0.0f);
 self->outputHeight=p->height;
 self->initialHeight=p->initialHeight;
 self->direction.set(0.0f,1.0f,0.0f);
 self->position.set(0.0f,self->initialHeight,0.0f);
 self->position.add(self->origin);
 self->rate=self->otherRate=p->rate;
 self->velocity.set(0.0f,0.0f,0.0f);
 self->acceleration.set(0.0f,0.0f,0.0f);
 self->flags=p->flags;
 self->outputAngle=self->angle+p->angle+3.1415927410125732421875f;
 test_800d4b90(self,&self->outputAngle,&self->outputHeight);
}

// These offsets and scalar sizes are specific to the 32-bit GameCube ABI.
typedef char Sol31aResetPointer32[sizeof(Ptr32<void>)==4?1:-1];
typedef char Sol31aResetFloat32[sizeof(float)==4?1:-1];
typedef char Sol31aResetHandleOffset[__builtin_offsetof(Sol31aResetMotion,handle)==136?1:-1];
typedef char Sol31aResetPositionOffset[__builtin_offsetof(Sol31aResetMotion,position)==88?1:-1];
typedef char Sol31aResetOutputOffset[__builtin_offsetof(Sol31aResetMotion,outputAngle)==176?1:-1];
typedef char Sol31aResetFlagsOffset[__builtin_offsetof(Sol31aResetMotion,flags)==196?1:-1];
typedef char Sol31aResetParameterFlagsOffset[__builtin_offsetof(Sol31aResetParameters,flags)==136?1:-1];


