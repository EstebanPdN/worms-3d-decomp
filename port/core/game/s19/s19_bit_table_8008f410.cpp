#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_bit_table_8008f410.c"
extern Ptr32<unsigned char> lbl_804b1800;

void s19_build_bit_table_8008f410(void)
{
    unsigned i;
    for (i = 0; i <= 255; i++) {
        if ((i & 15) && (i & 240)) {
            lbl_804b1800[i] = 7;
        } else {
            unsigned char v = i;
            unsigned char count = 0;
            int j;
            for (j = 0; j < 8; j++) {
                count += v & 1;
                v >>= 1;
            }
            lbl_804b1800[i] = count;
        }
    }
}

}
