/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_worm_attach_alternate_80139858)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_empty_80343584 = 0x80343584;
w3d_f32_8039f6e4 = 0x8039f6e4;
w3d_f32_8039f6e8 = 0x8039f6e8;
w3d_f32_8039f6f0 = 0x8039f6f0;
w3d_f32_8039f78c = 0x8039f78c;
w3d_f32_8039f790 = 0x8039f790;
w3d_f32_8039f794 = 0x8039f794;
w3d_fn_800ccd04 = 0x800ccd04;
w3d_fn_800cd0d0 = 0x800cd0d0;
w3d_fn_800cd13c = 0x800cd13c;
w3d_fn_800cd7fc = 0x800cd7fc;
w3d_fn_800da4a8 = 0x800da4a8;
w3d_fn_80164fc8 = 0x80164fc8;
w3d_fn_80181814 = 0x80181814;
w3d_mesh_instance_is_playing = 0x80181ccc;
w3d_mesh_instance_set_resource_value = 0x80182410;
w3d_worm_play_named_801359ec = 0x801359ec;
SECTIONS {
  .text.w3d_worm_attach_alternate_80139858 0x80139858 : { *(.text.w3d_worm_attach_alternate_80139858) }
  .text.w3d_worm_attach_component_mesh_80139900 0x80139900 : { *(.text.w3d_worm_attach_component_mesh_80139900) }
  .text.w3d_worm_update_movement_80139f1c 0x80139f1c : { *(.text.w3d_worm_update_movement_80139f1c) }
  .text.w3d_worm_update_blend_8013a0d4 0x8013a0d4 : { *(.text.w3d_worm_update_blend_8013a0d4) }
  .text.w3d_angle_delta_8013aa10 0x8013aa10 : { *(.text.w3d_angle_delta_8013aa10) }
  .sdata 0x804ab16c (NOLOAD) : {
    . = 0x0; w3d_obj_804ab16c = .;
    . = 0x20; w3d_obj_804ab18c = .;
    . = 0x24; w3d_obj_804ab190 = .;
    . = 0x2c; w3d_obj_804ab198 = .;
    . = 0x1c8; w3d_obj_804ab334 = .;
    . = 0x1cc; w3d_obj_804ab338 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
