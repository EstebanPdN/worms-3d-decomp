#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_leaf_q.c"
/* Forwarding helper that calls two virtual methods of objects held by a global. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
typedef struct S20Services { char pad0[100]; Ptr32<S20Object> service100; char pad1[4]; Ptr32<S20Object> service108; } S20Services;
extern Ptr32<S20Services> lbl_804b1788;
typedef Ptr32<void (Ptr32<S20Object>)> S20Call0;

void w3d_s20_notify_if_flagged_800e8ee0(Ptr32<char> self, Ptr32<char> flag, Ptr32<Ptr32<S20Object>> target) {
    Ptr32<Ptr32<S20Object>> copy;
    copy = target;
    if (*flag != 0) {
        Ptr32<S20Object> second;
        Ptr32<S20Object> first = lbl_804b1788->service108;
        do {
            ((S20Call0)first->vtable[23])(first);
        } while (0);
        second = *copy;
        ((S20Call0)second->vtable[5])(second);
    }
}

}
