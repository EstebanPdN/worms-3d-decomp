#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cg_802ad9c0.c"
// desc: Appears to verify a CRC: it computes the checksum of a buffer, logs both values on a mismatch and returns zero, else returns one.
extern const char lbl_803d7494[];
extern unsigned fn_802ad978(Ptr32<const void>, unsigned);
extern int fn_802fb7ac(Ptr32<const char>, ...);
int w3d_s21_verify_crc_802ad9c0(Ptr32<const void> data, unsigned length, unsigned expected)
{
    unsigned actual = fn_802ad978(data, length);
    if (expected == actual)
        return 1;
    fn_802fb7ac(lbl_803d7494, expected, actual);
    return 0;
}

}
