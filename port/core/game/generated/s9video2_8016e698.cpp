#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9video2_8016e698.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S9VideoRelease {
    Ptr32<void> buffer;
    char unknown4[552];
    int ready;
} S9VideoRelease;
extern void fn_801fe2e0(Ptr32<void>);
extern int fn_802fb7ac(Ptr32<const char>,...);
extern char lbl_803a6398[];

void s9_release_video_buffer_8016e698(Ptr32<S9VideoRelease> self)
{
    if(self->ready) {
        if(self->buffer)fn_801fe2e0(self->buffer);
        self->buffer=0;
        fn_802fb7ac(lbl_803a6398);
    }
    self->ready=0;
}

}
