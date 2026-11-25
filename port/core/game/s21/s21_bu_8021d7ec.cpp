#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bu_8021d7ec.c"
// desc: Appears to update a table-driven CRC value over a byte buffer using a global lookup table and return the result.
extern unsigned lbl_804a98f8[];
unsigned w3d_s21_crc_update_8021d7ec(unsigned crc, Ptr32<const unsigned char> data, unsigned length)
{
    while (length--) {
        crc = (crc >> 8) ^ lbl_804a98f8[(crc & 0xff) ^ *data];
        data++;
    }
    return crc;
}

}
