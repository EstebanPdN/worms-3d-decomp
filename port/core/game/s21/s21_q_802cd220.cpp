#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_q_802cd220.c"
// desc: Appears to run a setup helper and then issue the same request 25 times with a shared global argument.
extern int lbl_804abcd4;
extern void fn_802cd128(Ptr32<void>);
extern void fn_802cc0ac(Ptr32<void>, int, int);
void w3d_s21_repeat_request_802cd220(Ptr32<void> self)
{
    unsigned i = 0;
    fn_802cd128(self);
    do {
        fn_802cc0ac(self, lbl_804abcd4, 9);
        i++;
    } while (i <= 24);
}

}
