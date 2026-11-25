#include "w3d_ptr.h"
#line 1 "cx7a_state_two_enter_80038354.cpp"

// State +0x5c becomes 2; deadline +0x58 is clock plus unsigned float duration
// read through the value object at +0x3c. Concrete state meaning is inferred.
struct Cx7aValue;
struct Cx7aState {unsigned char unknown00[60];Ptr32<Cx7aValue> duration;unsigned char unknown40[24];unsigned int deadline;int state;};
extern "C" int refresh_8003864c(Ptr32<Cx7aState>);
extern "C" unsigned int clock_801fe45c();
extern "C" float value_80178df0(Ptr32<Cx7aValue>);
extern "C" void w3d_cx7a_state_two_enter_80038354(Ptr32<Cx7aState> self) {refresh_8003864c(self);self->state=2;unsigned int now=clock_801fe45c();self->deadline=now+(unsigned int)value_80178df0(self->duration);}


