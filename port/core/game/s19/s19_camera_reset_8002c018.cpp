#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_camera_reset_8002c018.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<void (Ptr32<S19Iface>, Ptr32<void>)> S19Set;
struct S19Message { unsigned short id; unsigned short pad2; Ptr32<void> type; };
struct S19Cache { int words[2]; };
struct S19Ctx { char pad0[48]; Ptr32<S19Iface> camera; char pad52[136]; unsigned flags; };
extern Ptr32<struct S19Ctx> lbl_804b1788;
extern Ptr32<void> lbl_804b1754;
extern struct S19Cache lbl_804acc90;
extern unsigned char lbl_8040db38[];
extern Ptr32<void> FUN_801613f0(Ptr32<void>, int);
extern short w3d_cached_message_id(Ptr32<struct S19Cache>, int);
extern int w3d_message_post_current(Ptr32<void>);

void s19_post_camera_reset_8002c018(Ptr32<void> self)
{
    Ptr32<struct S19Message> m;
    ((S19Set)lbl_804b1788->camera->vtable[10])(lbl_804b1788->camera, (Ptr32<char>)self + 100);
    ((S19Set)lbl_804b1788->camera->vtable[10])(lbl_804b1788->camera, (Ptr32<char>)self + 128);
    lbl_804b1788->flags &= ~4u;
    m = (Ptr32<struct S19Message>)FUN_801613f0(lbl_804b1754, 8);
    m->id = w3d_cached_message_id(&lbl_804acc90, 1);
    m->type = lbl_8040db38;
    w3d_message_post_current(m);
}

}
