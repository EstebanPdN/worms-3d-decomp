#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9actor2_8013c890.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Partial actor interface and handle fields inferred from accesses. */
typedef struct S9ActorInterface {Ptr32<Ptr32<void>> vtable;} S9ActorInterface;
typedef struct S9ActorState {
    char unknown0[148];
    unsigned int handle;
    char unknown152[12];
    Ptr32<S9ActorInterface> primary; Ptr32<S9ActorInterface> secondary;
    char unknown172[388];
    unsigned int first_handle,second_handle;
    char unknown568[164];
    int inhibited;
    char unknown736[8];
    unsigned int interface_state;
} S9ActorState;
extern void fn_800e5bb8(unsigned int);
extern int fn_8013f844(Ptr32<S9ActorState>);
extern int fn_80139158(Ptr32<S9ActorState>);
extern Ptr32<void> fn_80164fc8(unsigned int);
extern void fn_800da818(Ptr32<void>,unsigned int);

void s9_update_actor_interfaces_8013c890(Ptr32<S9ActorState> self,unsigned int value)
{
    unsigned int state=value^1;
    Ptr32<void> object;
    self->interface_state=state;
    if(!self->inhibited && fn_80139158(self)) {
        if(self->primary)((Ptr32<void (Ptr32<S9ActorInterface>, unsigned int)>)self->primary->vtable[22])(self->primary,state);
        if(self->secondary)((Ptr32<void (Ptr32<S9ActorInterface>, unsigned int)>)self->secondary->vtable[22])(self->secondary,state);
        if(self->handle && (object=fn_80164fc8(self->handle)))fn_800da818(object,state);
    }
}

void s9_clear_actor_handles_8013e3d4(Ptr32<S9ActorState> self)
{
    Ptr32<S9ActorInterface> replacement;
    if(self->first_handle)fn_800e5bb8(self->first_handle);
    self->first_handle=0;
    if(self->second_handle)fn_800e5bb8(self->second_handle);
    self->second_handle=0;
    replacement=w3d::G(fn_8013f844(self));
    if(!replacement) {
        if(self->secondary)((Ptr32<void (Ptr32<S9ActorInterface>)>)self->secondary->vtable[4])(self->secondary);
        self->secondary=replacement;
    }
}

}
