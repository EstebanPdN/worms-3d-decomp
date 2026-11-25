#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_cell_800bd9d0.c"
extern Ptr32<void> lbl_804ae5e0;
extern int lbl_804b1854;
extern unsigned lbl_804b1858;
extern struct { Ptr32<Ptr32<void>> table; int pad[3]; } lbl_8043bb64;
extern Ptr32<void> w3d_constructor_native_cast(Ptr32<void>);
extern int w3d_auto_80178d1c(Ptr32<void>);
extern void FUN_800b46bc(Ptr32<void>, unsigned, unsigned, unsigned);

void s19_apply_cell_800bd9d0(void)
{
    if (!w3d_auto_80178d1c(w3d_constructor_native_cast(lbl_804ae5e0))) {
        int index = lbl_804b1854;
        unsigned packed = lbl_804b1858;
        FUN_800b46bc(*(Ptr32<Ptr32<void>>)((Ptr32<char>)lbl_8043bb64.table + (index << 2)), packed & 255, (packed >> 8) & 255, (packed >> 16) & 255);
    }
}

}
