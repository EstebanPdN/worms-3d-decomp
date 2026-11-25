/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9b_text_repeat_byte_8020d600)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fill_802eefe0 = 0x802eefe0;
SECTIONS {
  .text.w3d_cx9b_text_repeat_byte_8020d600 0x8020d600 : { *(.text.w3d_cx9b_text_repeat_byte_8020d600) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
