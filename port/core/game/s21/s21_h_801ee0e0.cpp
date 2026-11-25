#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_h_801ee0e0.c"
struct S21Table { char pad[24]; unsigned count; int reserved; int items[1]; };
int w3d_s21_table_find_801ee0e0(Ptr32<struct S21Table> table, int value, Ptr32<unsigned int> index)
{
    unsigned i = 0;
    Ptr32<int> item = table->items;
    if (i < table->count) {
        do {
            if (*item++ == value) {
                *index = i;
                return 0;
            }
            i++;
        } while (i < table->count);
    }
    return 0x80004005;
}

}
