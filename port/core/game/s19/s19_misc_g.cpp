#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_misc_g.c"
extern int FUN_800b6800(Ptr32<void>);
extern int lbl_804b17ac;
extern struct { Ptr32<char> table; int pad[3]; } lbl_8043bb64;
void s19_dispatch_indexed_800bd920(void) {
    int i = lbl_804b17ac;
    FUN_800b6800(*(Ptr32<Ptr32<void>>)(lbl_8043bb64.table + (i << 2)));
}

}
