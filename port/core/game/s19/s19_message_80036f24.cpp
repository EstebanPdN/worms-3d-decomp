#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_message_80036f24.c"
struct S19Message { unsigned short id; };
extern int w3d_auto_8016293c(Ptr32<void>, Ptr32<struct S19Message>);
extern void FUN_800370cc(Ptr32<void>);

int s19_handle_message_80036f24(Ptr32<void> self, Ptr32<struct S19Message> msg)
{
    if (msg->id == 64) {
        if (w3d_auto_8016293c(self, msg) >= 0) {
            FUN_800370cc(self);
            return 0;
        }
        return 0x80004005;
    }
    return w3d_auto_8016293c(self, msg);
}

}
