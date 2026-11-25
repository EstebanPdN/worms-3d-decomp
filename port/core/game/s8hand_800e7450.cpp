#include "w3d_ptr.h"
#line 1 "s8hand_800e7450.cpp"
struct s8_StopOwner { char pad0[16]; char descriptor[64]; Ptr32<void> handle; };
extern "C" int fn_800b01b0(Ptr32<void>,Ptr32<void>);
extern "C" int fn_800b0100(Ptr32<void>,int);
extern "C" void s8_guarded_stop_800e7450(Ptr32<s8_StopOwner> self) {
    if(self->handle && fn_800b01b0(self->handle,self->descriptor)) {
        if(self->handle) fn_800b0100(self->handle,3);
        self->handle=0;
    }
}


