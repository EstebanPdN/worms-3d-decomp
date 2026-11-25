#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_message_80024dcc.c"
struct S19Message { unsigned short id; unsigned short pad2; Ptr32<void> type; };
struct S19Cache { int words[2]; };
extern struct S19Cache lbl_804aca8c;
extern struct S19Cache lbl_804aca94;
extern unsigned char lbl_8040db38[];
extern Ptr32<void> lbl_804b1754;
extern int w3d_auto_8015fb34(Ptr32<void>, Ptr32<struct S19Message>);
extern int w3d_message_id_equals_cache(int, Ptr32<struct S19Cache>);
extern int w3d_auto_80024f64(Ptr32<void>);
extern void w3d_set_handle_owner_80024f00(Ptr32<void>, int);
extern void FUN_80024ea0(Ptr32<void>);
extern Ptr32<void> FUN_801613f0(Ptr32<void>, int);
extern short w3d_cached_message_id(Ptr32<struct S19Cache>, int);
extern int w3d_message_post_current(Ptr32<void>);

int s19_handle_message_80024dcc(Ptr32<void> self, Ptr32<struct S19Message> msg)
{
    if (msg->id == 64) {
        if (w3d_auto_8015fb34(self, msg) >= 0)
            FUN_80024ea0(self);
        else
            return 0x80004005;
    } else {
        if (!w3d_message_id_equals_cache(msg->id, &lbl_804aca8c))
            return w3d_auto_8015fb34(self, msg);
        w3d_set_handle_owner_80024f00(self, w3d_auto_80024f64(self) ^ 1);
        {
            Ptr32<struct S19Message> m = (Ptr32<struct S19Message>)FUN_801613f0(lbl_804b1754, 8);
            m->id = w3d_cached_message_id(&lbl_804aca94, 1);
            m->type = lbl_8040db38;
            w3d_message_post_current(m);
        }
    }
    return 0;
}

}
