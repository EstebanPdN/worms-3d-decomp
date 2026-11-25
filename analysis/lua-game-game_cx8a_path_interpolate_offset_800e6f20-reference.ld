/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx8a_path_interpolate_offset_800e6f20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
one_8038afb8 = 0x8038afb8;
SECTIONS {
  .text.w3d_cx8a_path_interpolate_offset_800e6f20 0x800e6f20 : { *(.text.w3d_cx8a_path_interpolate_offset_800e6f20) }
  .rodata 0x8038afb0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
