
// State +0x5c transitions to 3; notify a byte-valued held object, refresh,
// then clear +0x58. The state names are not known.
struct Cx7aByteValue { unsigned char value; unsigned char spare[7]; };
struct Cx7aHeld;
struct Cx7aState { unsigned char unknown00[0x30];Cx7aHeld *held;unsigned char unknown34[0x24];int pending;int state; };
extern "C" int byte_store_80173f88(Cx7aHeld *,const Cx7aByteValue *);
extern "C" int refresh_80038684(Cx7aState *);
extern "C" void w3d_cx7a_state_three_enter_800382f4(Cx7aState *self) { if(self->state!=3) { self->state=3;Cx7aByteValue value;value.value=0;byte_store_80173f88(self->held,&value);refresh_80038684(self);self->pending=0; } }
