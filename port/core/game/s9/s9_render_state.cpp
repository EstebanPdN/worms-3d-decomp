#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9_render_state.c"
/* Observed render-state fields. Meanings beyond mode/cache/dirty flag are inferred. */
typedef struct S9RenderState {
    char unknown_0[236];
    int mode;
    char unknown_240[4];
    int cached_mode;
    char unknown_248[5020];
    int dirty_flags;
} S9RenderState;
typedef struct S9Material {
    char unknown_0[304];
    int value_304;
} S9Material;
int fn_8016857C(Ptr32<void>, int);               /* extern */
int fn_8016A1E8(Ptr32<void>, int);               void fn_803080A4(int);                       void fn_8030990C(int);                       void fn_80309948(int, int, int, int, int, int, int); void fn_8030B058(int, int, int, int, int); void fn_8030B4AC(int, int, int, int); void fn_8030B648(int);                       /* extern */

void s9_apply_render_state_80167dd4(Ptr32<S9RenderState> state, int material_base) {
    int blend_enabled;
    int blend_factor;
    int operation;
    int alpha_value;
    int mode;
    int dirty_flags;
    int requested_mode;
    int special_mode;
    int material_value;
    Ptr32<S9Material> material;

    dirty_flags = state->dirty_flags;
    if (dirty_flags & 0x20000000) {
        goto block_2;
    }
    if ((int) state->cached_mode == (int) state->mode) {
        goto block_26;
    }
block_2:
    requested_mode = state->mode;
    state->dirty_flags = (int) (dirty_flags & 0xDFFFFFFF);
    blend_enabled = 0;
    state->cached_mode = requested_mode;
    special_mode = 0;
    material = material_base ? w3d::R((Ptr32<S9Material>)w3d::G((material_base - 4))) : 0;
block_4:
    operation = 0xFF;
    blend_factor = 1;
    if (!(requested_mode & 4)) {
        goto block_6;
    }
    fn_8016857C(state, 0);
    operation = 0;
    blend_factor = 0;
    special_mode = 1;
    goto block_10;
block_6:
    if (!(requested_mode & 0x10)) {
        goto block_8;
    }
    operation = 4;
    blend_factor = 0;
    goto block_10;
block_8:
    if (!(requested_mode & 8)) {
        goto block_11;
    }
    operation = 4;
block_10:
    blend_enabled = 1;
block_11:
    mode = state->mode;
    if (!(mode & 0x20)) {
        goto block_20;
    }
    material_value = material ? material->value_304 : 0;
block_14:
    alpha_value = 0;
    if (mode & 0x40) {
        goto block_18;
    }
    if (!(mode & 0x80)) {
        goto block_17;
    }
    fn_8030B058(0, 7, 7, 7, 5);
    state->cached_mode = 0;
    state->mode = (int) (state->mode & 0xFFFFFF7F);
    goto block_23;
block_17:
    if (!(mode & 4)) {
        goto block_19;
    }
block_18:
    fn_8030B058(0, 7, 7, 7, 4);
    goto block_23;
block_19:
    fn_8030B058(0, 7, 4, 5, 7);
    goto block_23;
block_20:
    material_value = 0xFF;
    fn_803080A4(0);
    alpha_value = 0xFF;
    fn_8030B648(1);
    if (material == 0) {
        goto block_22;
    }
    fn_8016A1E8(material, 4);
block_22:
    fn_8030B058(0, 7, 7, 7, 5);
block_23:
    fn_8030B4AC(0, material_value, alpha_value, operation);
    if (special_mode == 0) {
        goto block_25;
    }
    fn_80309948(0, 1, blend_factor, blend_factor, 1, 2, 2);
    fn_8030990C(blend_enabled);
    return;
block_25:
    fn_80309948(4, 0, blend_factor, blend_factor, 0, 0, 2);
    fn_8030990C(blend_enabled);
block_26:
    return;
}

}
