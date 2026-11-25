#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_msg_800b92a4.c"
struct S19V3 { float x, y, z; };
struct S19Msg { unsigned short id; unsigned short pad2; Ptr32<void> type; float value; struct S19V3 pos; };
struct S19Cache { int words[2]; };
extern struct S19Cache lbl_804ae510;
extern unsigned char lbl_8040db38[];
extern short w3d_cached_message_id(Ptr32<struct S19Cache>, int);

Ptr32<struct S19Msg> s19_msg_init_800b92a4(Ptr32<struct S19Msg> m, Ptr32<struct S19V3> pos, float value)
{
    m->id = w3d_cached_message_id(&lbl_804ae510, 1);
    m->type = lbl_8040db38;
    m->pos = *pos;
    m->value = value;
    return m;
}

}
