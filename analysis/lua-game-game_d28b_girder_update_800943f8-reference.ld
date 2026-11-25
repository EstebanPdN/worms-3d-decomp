/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28b_girder_update_800943f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8037ea24 = 0x8037ea24;
lbl_8037ea34 = 0x8037ea34;
lbl_8037ea44 = 0x8037ea44;
lbl_8037ea58 = 0x8037ea58;
lbl_80434b88 = 0x80434b88;
w3d_camera_set_80035714 = 0x80035714;
w3d_cancel_800959cc = 0x800959cc;
w3d_cast_80342fa4 = 0x80342fa4;
w3d_clamp_800949a8 = 0x800949a8;
w3d_euler_801a3eb0 = 0x801a3eb0;
w3d_heading_80095450 = 0x80095450;
w3d_input_80094a84 = 0x80094a84;
w3d_points_80095b58 = 0x80095b58;
w3d_read_float_800fc270 = 0x800fc270;
w3d_read_int_800fc1f0 = 0x800fc1f0;
w3d_set_vec_80178fa4 = 0x80178fa4;
w3d_timer_is_one_8006e71c = 0x8006e71c;
w3d_track_80095db4 = 0x80095db4;
w3d_update_value_80178c54 = 0x80178c54;
w3d_worm_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.w3d_d28b_girder_update_800943f8 0x800943f8 : { *(.text.w3d_d28b_girder_update_800943f8) }
  .rodata 0x8037ea64 : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; lbl_804aa8c8 = .;
    . = 0x3560; lbl_804ade28 = .;
    . = 0x6ec0; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
