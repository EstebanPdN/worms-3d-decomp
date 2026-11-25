#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_80167fe0.c"
struct K4bState {
    char pad0[0xe8];
    int field_e8;
    int mode;
    int field_f0;
    int field_f4;
    char pad_f8[4];
    int field_fc;
};
extern void fn_80307558(void);
extern void w3d_state_apply_8016797c(Ptr32<struct K4bState> self, int a, int b, int c);
void w3d_k4b_state_reset_80167fe0(Ptr32<struct K4bState> self)
{
    self->mode = 2;
    self->field_e8 = 0;
    self->field_fc = 0;
    self->field_f4 = 0;
    self->field_f0 = 0;
    fn_80307558();
    w3d_state_apply_8016797c(self, 0, 1, 0);
}
// desc: w3d_k4b_state_reset_80167fe0: Appears to reset five state words (mode set to two), call an SDK routine and reapply the state through 0x8016797c with arguments (0, 1, 0).

}
