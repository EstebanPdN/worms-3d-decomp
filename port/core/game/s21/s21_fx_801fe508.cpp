#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fx_801fe508.c"
// desc: Appears to convert a value times eight into ticks by dividing by the bus clock at 0x800000f8 divided by 500000.
extern unsigned lbl_80000000[];
unsigned w3d_s21_to_ticks_801fe508(unsigned value)
{
    return (value << 3) / (lbl_80000000[62] / 500000);
}

}
