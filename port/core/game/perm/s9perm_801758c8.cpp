#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9perm_801758c8.c"
/* State field observed at byte offset 20. */
typedef struct S9Status { char unknown[20]; int value; } S9Status;
int s9_permute_801758c8(Ptr32<const S9Status> self)
{
    if (self->value == 0) return 0x80004005;
    return 0x80004001;
}

}
