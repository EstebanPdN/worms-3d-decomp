#include "w3d_ptr.h"
#line 1 "motion_flags_800ed938.cpp"
// Reference dispatch at 0x800ed938. Both halves of its flag argument arrive
// in r5/r6 and survive the lookup calls. The first low-bit test can use its
// low word directly; the second comparison uses the original zero-high-word
// OR with the masked low word. A 64-bit unsigned flag parameter reproduces
// both operations and the otherwise unexplained saved high-half register.
// Layout and behavior are structural: the field names describe selection,
// while the ultimate motion/effect meaning remains inferred.
struct Sol29aMotionParameters {unsigned char unknown0[448];int ordinary;unsigned char unknown452[16];int lowBit,highBit;};
struct Sol29aMotion {unsigned char unknown0[192];Ptr32<void> parameterHandle;};
extern "C" Ptr32<void> lookup_80341584(Ptr32<void>);
extern "C" Ptr32<Sol29aMotionParameters> parameters_801797b4(Ptr32<void>);
extern "C" void apply_800ec6a8(Ptr32<Sol29aMotion>,Ptr32<void>,Ptr32<void>,Ptr32<void>);
typedef char Sol29aMotionHandleOffset[__builtin_offsetof(Sol29aMotion,parameterHandle)==192?1:-1];
typedef char Sol29aMotionOrdinaryOffset[__builtin_offsetof(Sol29aMotionParameters,ordinary)==448?1:-1];
typedef char Sol29aMotionLowOffset[__builtin_offsetof(Sol29aMotionParameters,lowBit)==468?1:-1];
typedef char Sol29aMotionHighOffset[__builtin_offsetof(Sol29aMotionParameters,highBit)==472?1:-1];
extern "C" void sol29a_motion_flags_800ed938(Ptr32<Sol29aMotion> self,unsigned unused,unsigned long long flags,unsigned other,Ptr32<void> velocity,Ptr32<void> acceleration){
 Ptr32<Sol29aMotionParameters> p=parameters_801797b4(lookup_80341584(self->parameterHandle));
 int enabled;
 if(flags&1ULL)enabled=p->lowBit;
 else if(flags&0x40000000ULL)enabled=p->highBit;
 else enabled=p->ordinary;
 if(enabled)apply_800ec6a8(self,(Ptr32<char>)self+36,velocity,acceleration);
}


