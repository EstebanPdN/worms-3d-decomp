/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28b_launch_effect_8009aaac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
f7b_direction_angles_8009b070 = 0x8009b070;
lbl_8040db38 = 0x8040db38;
lbl_8045e788 = 0x8045e788;
sqrt_802e82c0 = 0x802e82c0;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_euler_801a3eb0 = 0x801a3eb0;
w3d_lookup_80164fc8 = 0x80164fc8;
w3d_message_post_8016239c = 0x8016239c;
w3d_read_time_800fc1f0 = 0x800fc1f0;
w3d_read_vec_800fc2f0 = 0x800fc2f0;
w3d_worm_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.w3d_d28b_launch_effect_8009aaac 0x8009aaac : { *(.text.w3d_d28b_launch_effect_8009aaac) }
  .rodata 0x8037ffbc : { *(.rodata) }
  .sdata 0x804adfbc (NOLOAD) : {
    . = 0x0; lbl_804adfbc = .;
    . = 0x3798; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
