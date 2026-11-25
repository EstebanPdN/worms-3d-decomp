#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_message_80037bac.c"
struct S19Message { unsigned short id; };
struct S19Cache { int words[2]; };
extern struct S19Cache lbl_804ad050;
extern struct S19Cache lbl_804ad058;
extern int w3d_auto_8015fb34(Ptr32<void>, Ptr32<struct S19Message>);
extern int w3d_message_id_equals_cache(int, Ptr32<struct S19Cache>);
extern void FUN_80037d14(Ptr32<void>);
extern void w3d_release_interface_800382a8(Ptr32<void>);
extern void FUN_80038354(Ptr32<void>);
extern void FUN_800382f4(Ptr32<void>);

int s19_handle_message_80037bac(Ptr32<void> self, Ptr32<struct S19Message> msg)
{
    switch (msg->id) {
    case 64:
        if (w3d_auto_8015fb34(self, msg) >= 0)
            FUN_80037d14(self);
        else
            return 0x80004005;
        break;
    case 66:
        w3d_release_interface_800382a8(self);
        return w3d_auto_8015fb34(self, msg);
    default:
        if (w3d_message_id_equals_cache(msg->id, &lbl_804ad050)) {
            FUN_80038354(self);
            break;
        }
        if (!w3d_message_id_equals_cache(msg->id, &lbl_804ad058))
            return w3d_auto_8015fb34(self, msg);
        FUN_800382f4(self);
        break;
    }
    return 0;
}

}
