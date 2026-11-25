/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__13D20eFontLabelUs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D20eStringPCc = 0x8020bb54;
__10D20eWidgetUs = 0x8021ef08;
_vt.13D20eFontLabel = 0x8041a488;
lbl_803b6408 = 0x803b6408;
w3d_empty_string_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.__13D20eFontLabelUs 0x8022240c : { *(.text.__13D20eFontLabelUs) }
  .rodata 0x803b6c9c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
