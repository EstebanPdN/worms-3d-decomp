#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_heap_800dc5bc.c"
extern unsigned w3d_auto_80209a20(Ptr32<void>);
extern Ptr32<void> w3d_heap_allocate(Ptr32<void>, unsigned);
extern int lbl_804aecac;
Ptr32<void> s19_heap_try_allocate_800dc5bc(unsigned size)
{
    if (size > w3d_auto_80209a20(&lbl_804aecac))
        return 0;
    return w3d_heap_allocate(&lbl_804aecac, size);
}

}
