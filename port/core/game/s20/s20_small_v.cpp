#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_v.c"
/* Slot release loops, pending flush, name lookups and a pooled destructor. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;

extern void fn_80209920(Ptr32<void>, int);
extern void fn_80167018(Ptr32<char>);
extern int lbl_804b00dc;

void w3d_s20_flush_pending_80167094(Ptr32<char> self) {
    unsigned int i = 0;
    if (i < *(Ptr32<unsigned int>)(self + 5256)) {
        Ptr32<int> slot = (Ptr32<int>)(self + 1160);
        do {
            int value = *slot;
            i++;
            slot++;
            fn_80209920(&lbl_804b00dc, value);
        } while (i < *(Ptr32<unsigned int>)(self + 5256));
    }
    if (*(Ptr32<int>)(self + 5256) != 0)
        fn_80167018(self);
    *(Ptr32<int>)(self + 5256) = 0;
}

extern void fn_800e77dc(Ptr32<char>);
extern void fn_8015a39c(Ptr32<char>, int);
extern int lbl_804b0044;
extern char lbl_80410138[];

void w3d_s20_destroy_pooled_800e7344(Ptr32<char> self, int flags) {
    *(Ptr32<Ptr32<char>>)(self + 72) = lbl_80410138;
    fn_800e77dc(self);
    if (*(Ptr32<Ptr32<S20Object>>)(self + 84) != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)(*(Ptr32<Ptr32<S20Object>>)(self + 84))->vtable[4])(*(Ptr32<Ptr32<S20Object>>)(self + 84));
    fn_8015a39c(self, 0);
    if (flags & 1)
        fn_80209920(&lbl_804b0044, (int)w3d::H(self));
}

extern int fn_800e5cf0(int, Ptr32<char>, Ptr32<char>, int, int);
extern char lbl_8039fc00[];
extern char lbl_8039fc08[];
extern char lbl_8039fc1c[];
extern char lbl_8039fc24[];

void w3d_s20_bind_names_8013e35c(Ptr32<char> self) {
    if (*(Ptr32<int>)(self + 168) != 0) {
        *(Ptr32<int>)(self + 560) = fn_800e5cf0(*(Ptr32<int>)(self + 168), lbl_8039fc00, lbl_8039fc08, -1, 0);
        *(Ptr32<int>)(self + 564) = fn_800e5cf0(*(Ptr32<int>)(self + 168), lbl_8039fc1c, lbl_8039fc24, -1, 0);
    }
}

}
