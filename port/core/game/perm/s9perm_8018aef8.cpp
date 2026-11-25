#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9perm_8018aef8.c"
/* Ready flag observed at byte offset 24. */
typedef struct S9ReadyState { char unknown[24]; unsigned int flags; } S9ReadyState;
int s9_permute_8018aef8(Ptr32<const S9ReadyState> self)
{
    if(!(self->flags & 0x8000))return 0x80004005;
    return 0;
}

}
