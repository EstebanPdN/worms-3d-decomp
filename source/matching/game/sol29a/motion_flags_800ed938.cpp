// Reference dispatch at 0x800ed938. Both halves of its flag argument arrive
// in r5/r6 and survive the lookup calls. The first low-bit test can use its
// low word directly; the second comparison uses the original zero-high-word
// OR with the masked low word. A 64-bit unsigned flag parameter reproduces
// both operations and the otherwise unexplained saved high-half register.
// Layout and behavior are structural: the field names describe selection,
// while the ultimate motion/effect meaning remains inferred.
struct Sol29aMotionParameters {unsigned char unknown0[448];int ordinary;unsigned char unknown452[16];int lowBit,highBit;};
struct Sol29aMotion {unsigned char unknown0[192];void *parameterHandle;};
extern "C" void *lookup_80341584(void *);
extern "C" Sol29aMotionParameters *parameters_801797b4(void *);
extern "C" void apply_800ec6a8(Sol29aMotion *,void *,void *,void *);
typedef char Sol29aMotionHandleOffset[(unsigned)&((Sol29aMotion*)0)->parameterHandle==192?1:-1];
typedef char Sol29aMotionOrdinaryOffset[(unsigned)&((Sol29aMotionParameters*)0)->ordinary==448?1:-1];
typedef char Sol29aMotionLowOffset[(unsigned)&((Sol29aMotionParameters*)0)->lowBit==468?1:-1];
typedef char Sol29aMotionHighOffset[(unsigned)&((Sol29aMotionParameters*)0)->highBit==472?1:-1];
extern "C" void sol29a_motion_flags_800ed938(Sol29aMotion *self,unsigned unused,unsigned long long flags,unsigned other,void *velocity,void *acceleration){
 Sol29aMotionParameters *p=parameters_801797b4(lookup_80341584(self->parameterHandle));
 int enabled;
 if(flags&1ULL)enabled=p->lowBit;
 else if(flags&0x40000000ULL)enabled=p->highBit;
 else enabled=p->ordinary;
 if(enabled)apply_800ec6a8(self,(char *)self+36,velocity,acceleration);
}
