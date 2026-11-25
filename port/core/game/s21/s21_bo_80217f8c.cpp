#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bo_80217f8c.c"
// desc: Appears to install a new global handler pointer, fill three callback slots in a hook table and return the previous handler.
extern Ptr32<void> lbl_804aba90;
extern int lbl_80400768[];
extern int fn_80217c6c(Ptr32<void>, Ptr32<void>, int);
extern int fn_80217cd4(int, Ptr32<void>);
extern void fn_80217dac(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>);
Ptr32<void> w3d_s21_install_hooks_80217f8c(Ptr32<void> handler)
{
    Ptr32<void> previous = lbl_804aba90;
    lbl_804aba90 = handler;
    lbl_80400768[3] = (int)w3d::H(fn_80217c6c);
    lbl_80400768[4] = (int)w3d::H(fn_80217cd4);
    lbl_80400768[5] = (int)w3d::H(fn_80217dac);
    return previous;
}

}
