/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__12D20eMenuItemUs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D20eStringPCc = 0x8020bb54;
__10D20eWidgetUs = 0x8021ef08;
_vt.12D20eMenuItem = 0x8041a410;
w3d_empty_string_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.__12D20eMenuItemUs 0x80223138 : { *(.text.__12D20eMenuItemUs) }
  .rodata 0x803b7250 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
