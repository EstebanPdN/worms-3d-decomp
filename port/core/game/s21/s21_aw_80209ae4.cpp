#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_aw_80209ae4.c"
// desc: Appears to clear a table of 256 words and return the table.
Ptr32<int> w3d_s21_clear_table_80209ae4(Ptr32<int> table)
{
    int i;
    Ptr32<int> item = table;
    for (i = 0; i < 256; i++)
        *item++ = 0;
    return table;
}

}
