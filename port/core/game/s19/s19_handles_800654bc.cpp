#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_handles_800654bc.c"
extern Ptr32<void> w3d_s20_lookup_handle_object_80164fc8(int);
extern void w3d_auto_8015fd1c(Ptr32<void>);
void s19_clear_handles_800654bc(Ptr32<void> self)
{
    Ptr32<int> p = (Ptr32<int>)((Ptr32<char>)self + 28);
    int i;
    for (i = 0; i < 4; i++, p++) {
        int h = *p;
        if (h) {
            Ptr32<void> object = w3d_s20_lookup_handle_object_80164fc8(h);
            if (object)
                w3d_auto_8015fd1c(object);
            *p = 0;
        }
    }
}

}
