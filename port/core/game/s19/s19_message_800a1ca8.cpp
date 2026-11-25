#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_message_800a1ca8.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<void (Ptr32<S19Iface>, int)> S19IfaceFn;
struct S19Message { unsigned short id; };
struct S19Cache { int words[2]; };
extern struct S19Cache lbl_804ae184;
extern int w3d_auto_8015fb34(Ptr32<void>, Ptr32<struct S19Message>);
extern int w3d_message_id_equals_cache(int, Ptr32<struct S19Cache>);
extern void FUN_800a20cc(Ptr32<void>);

int s19_handle_message_800a1ca8(Ptr32<void> self, Ptr32<struct S19Message> msg)
{
    if (msg->id == 64) {
        if (w3d_auto_8015fb34(self, msg) >= 0) {
            FUN_800a20cc(self);
            return 0;
        }
        return 0x80004005;
    }
    if (w3d_message_id_equals_cache(msg->id, &lbl_804ae184)) {
        FIELD(self, int, 148) = 0;
        ((S19IfaceFn)FIELD(self, S19Iface *, 52)->vtable[22])(FIELD(self, S19Iface *, 52), 0);
    }
    return w3d_auto_8015fb34(self, msg);
}

}
