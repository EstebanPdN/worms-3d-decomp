#include "w3d_ptr.h"
#line 1 "s8family_800e7b7c.cpp"
struct s8_Message { unsigned short id; };
extern "C" int fn_8016293c(Ptr32<void>,Ptr32<const s8_Message>);
extern "C" void fn_800e7be8(Ptr32<void>);
extern "C" int s8_message_initialize_800e7b7c(Ptr32<void> self,Ptr32<const s8_Message> message) {
    if(message->id==64) {
        if(fn_8016293c(self,message)>=0) {
            fn_800e7be8(self);
            return 0;
        }
        return (int)0x80004005;
    }
    return fn_8016293c(self,message);
}


