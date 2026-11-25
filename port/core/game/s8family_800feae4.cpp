#include "w3d_ptr.h"
#line 1 "s8family_800feae4.cpp"
struct s8_Message { unsigned short id; };
extern "C" int fn_8015fb34(Ptr32<void>,Ptr32<const s8_Message>);
extern "C" int fn_800fefe8(Ptr32<void>);
extern "C" int s8_message_initialize_800feae4(Ptr32<void> self,Ptr32<const s8_Message> message) {
    if(message->id==64) {
        if(fn_8015fb34(self,message)>=0) {
            fn_800fefe8(self);
            return 0;
        }
        return (int)0x80004005;
    }
    return fn_8015fb34(self,message);
}


