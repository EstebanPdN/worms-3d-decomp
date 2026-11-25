#include "w3d_ptr.h"
#line 1 "cx12b_focus_dispatch_802c3ff0.cpp"

struct Owner {unsigned char opaque[92];Ptr32<void> items[32];Ptr32<void> s220; Ptr32<void> s224; Ptr32<void> s228; Ptr32<void> s232;};
extern "C" void set_a_802c7bec(Ptr32<void>,int);extern "C" void set_b_802c688c(Ptr32<void>,int);
extern "C" void w3d_cx12b_focus_dispatch_802c3ff0(Ptr32<Owner> self,int state,unsigned int index){if(index<=31)set_a_802c7bec(self->items[index],state);else switch((int)index){case 32:set_a_802c7bec(self->s232,state);break;case 33:set_b_802c688c(self->s220,state);break;case 34:set_b_802c688c(self->s224,state);break;case 35:set_a_802c7bec(self->s228,state);break;}}




