/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc36b_scale_tick_802c6e50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc36b_scale_identity_803d8ddc = 0x803d8ddc;
cc36b_scale_step_x_803d8de0 = 0x803d8de0;
cc36b_scale_step_y_803d8dd8 = 0x803d8dd8;
SECTIONS {
  .text.w3d_cc36b_scale_tick_802c6e50 0x802c6e50 : { *(.text.w3d_cc36b_scale_tick_802c6e50) }
  .rodata 0x803d8dd0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
