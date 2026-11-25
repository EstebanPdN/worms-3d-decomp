/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_has_motion_input_8014c3f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_motion_get_input_direction = 0x8014c260;
SECTIONS {
  .text.w3d_k2b_has_motion_input_8014c3f4 0x8014c3f4 : { *(.text.w3d_k2b_has_motion_input_8014c3f4) }
  .rodata 0x803a14a0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
