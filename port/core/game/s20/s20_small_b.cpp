#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_b.c"
/* Handle-based helpers and paired releases. */
typedef struct S20Pair2 { int pad[19]; int held76; int held80; } S20Pair2;
extern void fn_800b0100(Ptr32<void>, int);

void w3d_s20_release_pair_800e77dc(Ptr32<S20Pair2> self) {
    if (self->held80) {
        fn_800b0100(w3d::G(self->held80), 3);
        self->held80 = 0;
    }
    if (self->held76) {
        fn_800b0100(w3d::G(self->held76), 3);
        self->held76 = 0;
    }
}

typedef struct S20Handle { char pad[144]; int handle; } S20Handle;
extern int fn_80164fc8(int);
extern float fn_800ae9ac(Ptr32<void>);
extern float fn_800ae9b4(Ptr32<void>);
extern int fn_80181814(int, int, float, float);
extern int lbl_804ab180;
extern int lbl_804ab17c;
extern float lbl_8039f6ec[];

void w3d_s20_apply_handle_pair_8013a048(Ptr32<S20Handle> self, int target) {
    int object;
    if (self->handle == -1)
        return;
    object = fn_80164fc8(self->handle);
    if (object == 0) {
        self->handle = -1;
        return;
    }
    fn_80181814(target, lbl_804ab180, fn_800ae9ac(w3d::G(object)), lbl_8039f6ec[0]);
    fn_80181814(target, lbl_804ab17c, fn_800ae9b4(w3d::G(object)), lbl_8039f6ec[0]);
}

int w3d_s20_state_in_set_8013d88c(Ptr32<char> self) {
    switch (*(Ptr32<unsigned int>)(self + 684)) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
    case 12: case 13: case 16: case 18: case 20: case 21: case 29: case 47:
        return 1;
    default:
        return 0;
    }
}

}
