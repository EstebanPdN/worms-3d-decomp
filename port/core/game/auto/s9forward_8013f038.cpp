#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9forward_8013f038.c"
/* Named tail particle-effect creation; object fields remain inferred. */
typedef struct S9TailEffectActor {
    char unknown0[28];
    unsigned int owner_handle;
    char unknown32[544];
    int tail_effect;
} S9TailEffectActor;
extern void fn_80140240(Ptr32<S9TailEffectActor>);
extern Ptr32<void> fn_80343584(unsigned int);
extern int fn_800e5cf0(Ptr32<void>,Ptr32<char>,Ptr32<char>,int,int);
extern char lbl_8039fd54[],lbl_8039fd5c[];
void s9_create_tail_effect_8013f038(Ptr32<S9TailEffectActor> self)
{
    Ptr32<void> owner;
    fn_80140240(self);
    owner=fn_80343584(self->owner_handle);
    self->tail_effect=fn_800e5cf0(owner,lbl_8039fd54,lbl_8039fd5c,-1,0);
}

}
