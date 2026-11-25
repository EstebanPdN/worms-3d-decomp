#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_bytes_80086288.c"
extern unsigned char lbl_804ada6c[8];
extern unsigned lbl_804addec;
extern unsigned lbl_804addf0;
extern unsigned lbl_804addf4;
extern unsigned lbl_804addf8;
extern unsigned lbl_804addfc;
extern unsigned lbl_804ade00;
extern unsigned lbl_804ade04;
extern unsigned lbl_804ade08;
extern Ptr32<unsigned char> lbl_804b1800;

void s19_load_byte_table_80086288(Ptr32<void> self)
{
    if (*(Ptr32<unsigned char>)((Ptr32<char>)self + 480) == 0) {
        lbl_804ada6c[0] = 4;
        lbl_804ada6c[1] = 4;
        lbl_804ada6c[2] = 4;
        lbl_804ada6c[3] = 4;
        lbl_804ada6c[4] = 4;
        lbl_804ada6c[5] = 4;
        lbl_804ada6c[6] = 4;
        lbl_804ada6c[7] = 4;
        return;
    }
    lbl_804ada6c[0] = lbl_804b1800[lbl_804addec];
    lbl_804ada6c[1] = lbl_804b1800[lbl_804addf0];
    lbl_804ada6c[2] = lbl_804b1800[lbl_804addf4];
    lbl_804ada6c[3] = lbl_804b1800[lbl_804addf8];
    lbl_804ada6c[4] = lbl_804b1800[lbl_804addfc];
    lbl_804ada6c[5] = lbl_804b1800[lbl_804ade00];
    lbl_804ada6c[6] = lbl_804b1800[lbl_804ade04];
    lbl_804ada6c[7] = lbl_804b1800[lbl_804ade08];
}

}
