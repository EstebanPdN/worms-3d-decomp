#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9video_8016e608.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Inferred video buffer setup and platform format branch. */
typedef struct S9VideoBuffer {
    Ptr32<void> buffer;
    char unknown4[552];
    int ready;
} S9VideoBuffer;
extern int fn_802fce18(void);
extern Ptr32<void> fn_801fe2a8(unsigned int,unsigned int);
extern int fn_802fb7ac(Ptr32<const char>,...);
extern int fn_802fd8e4(Ptr32<void>);
extern char lbl_803a6368[],lbl_803a6380[];

void s9_initialize_video_buffer_8016e608(Ptr32<S9VideoBuffer> self)
{
    if(fn_802fce18()==1) {
        self->buffer=fn_801fe2a8(0x120f00,0x20);
        fn_802fb7ac(lbl_803a6368);
    } else {
        self->buffer=fn_801fe2a8(0x20120,0x20);
        fn_802fb7ac(lbl_803a6380);
    }
    fn_802fd8e4(self->buffer);
    self->ready=1;
}

}
