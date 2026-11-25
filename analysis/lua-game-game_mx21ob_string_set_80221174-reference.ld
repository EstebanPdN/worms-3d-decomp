/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__15Mx21obStringSetUs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__12Mx21obWidgetUs = 0x8021ef08;
_vt.15Mx21obStringSet = 0x8041a500;
w3d_empty_string_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.__15Mx21obStringSetUs 0x80221174 : { *(.text.__15Mx21obStringSetUs) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
