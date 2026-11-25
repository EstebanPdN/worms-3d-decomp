/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_worm_play_named_801359ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_801359c8 = 0x801359c8;
w3d_auto_80178c48 = 0x80178c48;
w3d_cached_message_id = 0x8015f5a0;
w3d_empty_803426b4 = 0x803426b4;
w3d_empty_80343584 = 0x80343584;
w3d_f32_8039f634 = 0x8039f634;
w3d_f32_8039f638 = 0x8039f638;
w3d_f32_8039f63c = 0x8039f63c;
w3d_f32_8039f654 = 0x8039f654;
w3d_f32_8039f658 = 0x8039f658;
w3d_f32_8039f65c = 0x8039f65c;
w3d_fn_800e5bb8 = 0x800e5bb8;
w3d_fn_800fc330 = 0x800fc330;
w3d_fn_800fc6dc = 0x800fc6dc;
w3d_fn_801613f0 = 0x801613f0;
w3d_fn_80164fc8 = 0x80164fc8;
w3d_fn_80181640 = 0x80181640;
w3d_int_message_init_80125fdc = 0x80125fdc;
w3d_mesh_instance_control_3c = 0x801817e0;
w3d_mesh_instance_play_index = 0x801816d0;
w3d_mesh_instance_set_resource_value = 0x80182410;
w3d_message_post_current = 0x8016239c;
w3d_obj_803eb63c = 0x803eb63c;
w3d_worm_graphic_release_effect = 0x80140240;
SECTIONS {
  .text.w3d_worm_play_named_801359ec 0x801359ec : { *(.text.w3d_worm_play_named_801359ec) }
  .text.w3d_worm_play_index_80135a70 0x80135a70 : { *(.text.w3d_worm_play_index_80135a70) }
  .text.w3d_worm_play_type_animation_80138d24 0x80138d24 : { *(.text.w3d_worm_play_type_animation_80138d24) }
  .text.w3d_worm_restore_animation_80139084 0x80139084 : { *(.text.w3d_worm_restore_animation_80139084) }
  .text.w3d_worm_is_current_80139158 0x80139158 : { *(.text.w3d_worm_is_current_80139158) }
  .text.w3d_worm_release_effects_8013919c 0x8013919c : { *(.text.w3d_worm_release_effects_8013919c) }
  .text.w3d_worm_attach_resource_801397b0 0x801397b0 : { *(.text.w3d_worm_attach_resource_801397b0) }
  .sdata 0x804ab100 (NOLOAD) : {
    . = 0x0; w3d_obj_804ab100 = .;
    . = 0x238; w3d_obj_804ab338 = .;
    . = 0x4740; w3d_obj_804af840 = .;
    . = 0x6654; w3d_obj_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
