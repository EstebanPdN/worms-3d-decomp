/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26h_camera_spline_step_800b01b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
frames_80178d1c = 0x80178d1c;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
rename_801790bc = 0x801790bc;
segment_points_800afeb8 = 0x800afeb8;
table_8040db38 = 0x8040db38;
SECTIONS {
  .text.d26h_camera_spline_step_800b01b0 0x800b01b0 : { *(.text.d26h_camera_spline_step_800b01b0) }
  .rodata 0x80382338 : { *(.rodata) }
  .sdata 0x804ae460 (NOLOAD) : {
    . = 0x0; id_804ae460 = .;
    . = 0x32f4; g_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
