/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_string_assign)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
vsprintf = 0x802ed5e0;
w3d_string_assign_text = 0x8020bd58;
SECTIONS {
  .text.w3d_string_assign 0x8020bd38 : { *(.text.w3d_string_assign) }
  .text.w3d_string_format 0x8020c510 : { *(.text.w3d_string_format) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
