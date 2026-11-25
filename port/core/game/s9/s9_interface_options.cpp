#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9_interface_options.c"
/* Observed interface pointer at 28 and four 16-bit options at 20..26. */
#define S9_FIELD(p,T,o) (*(w3d::slot_t<T>)((char *)w3d::AG(p)+(o)))
int s9_set_interface_options_8016f3b4(Ptr32<void> self, Ptr32<Ptr32<void>> value, int unused, short a, short b, short c, short d) {
    Ptr32<Ptr32<void>> previous;
    Ptr32<void> table;

    if (value == 0) {
        goto block_2;
    }
    table = *value;
    S9_FIELD(table, Ptr32<int (Ptr32<Ptr32<void>>)> *, 0xC)(value);
block_2:
    previous = S9_FIELD(self, Ptr32<Ptr32<void>> *, 0x1C);
    if (previous == 0) {
        goto block_4;
    }
    S9_FIELD(*previous, Ptr32<int (Ptr32<void>)> *, 0x10)(previous);
block_4:
    S9_FIELD(self, Ptr32<Ptr32<void>> *, 0x1C) = value;
    S9_FIELD(self, short *, 0x14) = a;
    S9_FIELD(self, short *, 0x16) = b;
    S9_FIELD(self, short *, 0x18) = c;
S9_FIELD(self, short *, 0x1A) = d;
    return 0;
}

}
