/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28g_fall_body_step_800672c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
f7b_reflect_800675fc = 0x800675fc;
k5a_body_ease_and_grow_80067524 = 0x80067524;
rest_pos_8043ae20 = 0x8043ae20;
rest_vel_8045e788 = 0x8045e788;
sqrt_802e82c0 = 0x802e82c0;
sweep_800b0824 = 0x800b0824;
w3d_auto_80178df0 = 0x80178df0;
w3d_empty_80342a74 = 0x80342a74;
w3d_stamp_pair_capture_80067510 = 0x80067510;
SECTIONS {
  .text.w3d_d28g_fall_body_step_800672c4 0x800672c4 : { *(.text.w3d_d28g_fall_body_step_800672c4) }
  .rodata 0x8037a0c4 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; hits_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
