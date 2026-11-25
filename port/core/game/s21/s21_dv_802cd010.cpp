#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_dv_802cd010.c"
// desc: Appears to shut down a sixteen-entry table of handles when the subsystem is enabled and initialized: it releases every nonzero entry and clears the initialized flag.
extern int lbl_804abce4;
extern int lbl_804abce8;
extern int lbl_80473764[];
extern void fn_802cce78(Ptr32<void>);
void w3d_s21_shutdown_handles_802cd010(void)
{
    if (lbl_804abce4 && lbl_804abce8) {
        Ptr32<int> handle = lbl_80473764;
        Ptr32<int> last = handle + 15;
        do {
            int value = *handle;
            handle++;
            if (value)
                fn_802cce78(w3d::G(value));
        } while (handle <= last);
        lbl_804abce8 = 0;
    }
}

}
