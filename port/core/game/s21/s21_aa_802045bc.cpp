#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_aa_802045bc.c"
// desc: Appears to run a per-element helper over an array of words, stopping at the first negative status and returning zero otherwise.
extern int fn_8020430c(Ptr32<void>, Ptr32<int>);
int w3d_s21_apply_each_802045bc(Ptr32<void> stream, Ptr32<int> items, unsigned count)
{
    unsigned i = 0;
    if (i < count) {
        do {
            int status = fn_8020430c(stream, items);
            items++;
            if (status < 0)
                return status;
            i++;
        } while (i < count);
    }
    return 0;
}

}
