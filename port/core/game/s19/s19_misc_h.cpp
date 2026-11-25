#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_misc_h.c"
struct S19Cfg { char pad0[584]; int a584; int a588; int a592; int a596; };
struct S19Obj { char pad0[28]; Ptr32<void> src; char pad32[144]; int f176; int f180; char pad184[4]; int f188; };
extern Ptr32<void> FUN_80341584(Ptr32<void>);
extern Ptr32<struct S19Cfg> FUN_801797b4(Ptr32<void>);
extern void FUN_800e9830(Ptr32<struct S19Obj>, int);
extern void FUN_800e8ee0(Ptr32<struct S19Obj>, Ptr32<void>, Ptr32<int>);
extern int FUN_800e8f40(Ptr32<struct S19Obj>, Ptr32<void>);
void s19_init_from_config_8007070c(Ptr32<struct S19Obj> p) {
    Ptr32<struct S19Cfg> c;c = FUN_801797b4((Ptr32<void>)FUN_80341584(p->src));
    FUN_800e9830(p, c->a596);
    FUN_800e8ee0(p, w3d::G(c->a592), &p->f176);
    FUN_800e8ee0(p, w3d::G(c->a588), &p->f180);
    p->f188 = FUN_800e8f40(p, w3d::G(c->a584));
}

struct S19Message { unsigned short id; unsigned short pad2; Ptr32<void> type; };
struct S19Dispatcher { char pad0[20]; Ptr32<void> target; };
struct S19Cache { int words[2]; };
extern unsigned char lbl_8040db38[];
extern Ptr32<void> lbl_804b1754;
extern Ptr32<struct S19Dispatcher> lbl_804b1760;
extern struct S19Cache lbl_804aca0c;
extern Ptr32<void> FUN_801613f0(Ptr32<void>, int);
extern short w3d_cached_message_id(Ptr32<struct S19Cache>, int);
extern void w3d_message_dispatch(Ptr32<void>, Ptr32<void>, int);
struct S19Owner { char pad0[4]; int posted; };

int s19_post_message_80021898(Ptr32<struct S19Owner> p) {
    Ptr32<struct S19Message> m = (Ptr32<struct S19Message>)FUN_801613f0(lbl_804b1754, 8);
    m->id = w3d_cached_message_id(&lbl_804aca0c, 1);
    m->type = lbl_8040db38;
    w3d_message_dispatch(m, lbl_804b1760->target, 0);
    p->posted = 1;
    return 0;
}

}
