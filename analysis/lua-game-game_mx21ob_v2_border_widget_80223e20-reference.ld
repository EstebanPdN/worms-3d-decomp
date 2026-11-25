/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__20Mx21obFeBorderWidgetUs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__14Mx21obFeWidgetUs = 0x8021ef08;
_vt.20Mx21obFeBorderWidget = 0x8041a3c0;
w3d_empty_string_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_from_text = 0x8020bb54;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.__20Mx21obFeBorderWidgetUs 0x80223e20 : { *(.text.__20Mx21obFeBorderWidgetUs) }
  .rodata 0x803b76e4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
