#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10_mode_apply.c"
/* The caller exposes an interface four bytes into this observed state. */
typedef struct S10ModeState {
    char reserved[44];
    int mode;
    int primary;
    int secondary;
    int unknown56;
    int alternative;
} S10ModeState;
typedef struct S10PropertyNode {
    char reserved[24];
    int type;
    int value;
} S10PropertyNode;
typedef struct S10ModeTarget {
    char reserved[24];
    unsigned int flags;
    Ptr32<void> properties;
} S10ModeTarget;
extern int fn_801a3ba0(Ptr32<void>, Ptr32<S10ModeTarget>);
extern int fn_801d4544(Ptr32<S10ModeTarget>, Ptr32<void>);
extern int fn_801edf88(Ptr32<void>, Ptr32<const char>);
extern Ptr32<S10PropertyNode> fn_801ee034(Ptr32<void>, Ptr32<const char>);
extern char lbl_80364a54[];
extern char lbl_80364f54[];
int w3d_s10_apply_mode_801b12ec(Ptr32<void> interface, Ptr32<S10ModeTarget> target)
{
    Ptr32<S10ModeState> state = interface ? w3d::R((Ptr32<S10ModeState>)((Ptr32<char>)interface - 4)) : 0;
    int selected;
    Ptr32<S10PropertyNode> property;
    state->mode = 0;
    selected = (target->flags >> 1) & 3;
    if (selected == 0) {
        int result = fn_801a3ba0(interface, target);
        if (result < 0)
            return result;
    } else {
        state->mode = selected;
    }
    if (state->mode == 1)
        goto apply_primary;
    if (state->mode <= 1)
        goto inspect_property;
    if (state->mode != 2)
        goto inspect_property;
    if (fn_801edf88(target->properties, lbl_80364a54) == 0)
        fn_801d4544(target, w3d::G(state->alternative));
    goto inspect_property;
apply_primary:
    if (fn_801edf88(target->properties, lbl_80364f54) == 0)
        fn_801d4544(target, w3d::G(state->primary));
    fn_801d4544(target, w3d::G(state->secondary));
inspect_property:
    property = fn_801ee034(target->properties, lbl_80364f54);
    if (property && property->type == 1) {
        int value = property->value;
        if (value == 1) {
            fn_801d4544(target, w3d::G(state->secondary));
            state->mode = value;
        }
    }
    target->flags = (target->flags & 0xfffffff9) | ((unsigned int)state->mode << 1);
    return 0;
}

}
