#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "h1_801ee410.c"
/* Virtual-call helper (session 47b5d14a, hand-matched).
 * Offsets come from the original instructions; meanings are inferred. */

typedef struct W3dObject_801ee410 W3dObject_801ee410;
typedef struct W3dObjectVtbl_801ee410 {
    Ptr32<void> slots[4];
    Ptr32<void (Ptr32<W3dObject_801ee410>)> finish;       /* +16 */
    Ptr32<void> slot20;
    Ptr32<int (Ptr32<W3dObject_801ee410>)> result;        /* +24 */
} W3dObjectVtbl_801ee410;
struct W3dObject_801ee410 {
    Ptr32<W3dObjectVtbl_801ee410> vtbl;
};

int w3d_h1_result_then_finish_801ee410(Ptr32<W3dObject_801ee410> self)
{
    int result = self->vtbl->result(self);
    self->vtbl->finish(self);
    return result;
}

}
