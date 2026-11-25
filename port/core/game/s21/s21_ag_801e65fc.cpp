#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ag_801e65fc.c"
// desc: Appears to return the result of a virtual slot of the linked object, or zero when there is no link.
struct S21Link;
struct S21LinkMethods { Ptr32<void (void)> reserved[24]; Ptr32<int (Ptr32<struct S21Link>)> query; };
struct S21Link { Ptr32<struct S21LinkMethods> methods; };
struct S21Object { char pad[44]; Ptr32<struct S21Link> link; };
int w3d_s21_link_query_801e65fc(Ptr32<struct S21Object> self)
{
    if (self->link != 0)
        return self->link->methods->query(self->link);
    return 0;
}

}
