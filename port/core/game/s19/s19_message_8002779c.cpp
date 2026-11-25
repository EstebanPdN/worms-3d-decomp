#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_message_8002779c.c"
struct S19Message { unsigned short id; };
struct S19Cache { int words[2]; };
extern struct S19Cache lbl_804acb94;
extern int w3d_auto_8016293c(Ptr32<void>, Ptr32<struct S19Message>);
extern int w3d_message_id_equals_cache(int, Ptr32<struct S19Cache>);
extern void w3d_auto_80027d20(Ptr32<void>);

int s19_handle_message_8002779c(Ptr32<void> self, Ptr32<struct S19Message> msg)
{
    if (msg->id == 64) {
        if (w3d_auto_8016293c(self, msg) >= 0) {
            w3d_auto_80027d20(self);
            return 0;
        }
        return 0x80004005;
    }
    w3d_message_id_equals_cache(msg->id, &lbl_804acb94);
    return w3d_auto_8016293c(self, msg);
}

}
