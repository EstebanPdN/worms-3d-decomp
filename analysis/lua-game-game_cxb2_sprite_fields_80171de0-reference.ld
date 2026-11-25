/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cxb2_sprite_fields_80171de0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80190538 = 0x80190538;
lbl_803a66a8 = 0x803a66a8;
lbl_803a66b4 = 0x803a66b4;
lbl_803a66c0 = 0x803a66c0;
SECTIONS {
  .text.cxb2_sprite_fields_80171de0 0x80171de0 : { *(.text.cxb2_sprite_fields_80171de0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
