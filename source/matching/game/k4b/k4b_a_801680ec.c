extern int lbl_804ab4fc;
extern void *lbl_804b00e8;
extern void *fn_803031d0(void (*callback)(void));
extern void w3d_s20_set_blend_mode_8016830c(int mode);
extern void w3d_render_hook_8016814c(void);
void w3d_k4b_render_set_target_801680ec(void *target)
{
    if (target != 0) {
        lbl_804ab4fc = 1;
        lbl_804b00e8 = target;
        fn_803031d0(w3d_render_hook_8016814c);
        w3d_s20_set_blend_mode_8016830c(1);
    } else {
        lbl_804ab4fc = 0;
        lbl_804b00e8 = target;
        w3d_s20_set_blend_mode_8016830c(0);
        fn_803031d0(0);
    }
}
// desc: w3d_k4b_render_set_target_801680ec: Appears to install or clear a render target pointer, toggling a flag, a retrace-style callback (0x8016814c) and the blend mode through 0x8016830c.
