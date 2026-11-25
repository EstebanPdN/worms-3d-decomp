/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_choice_icon_802a62bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802a671c = 0x802a671c;
fn_802a6878 = 0x802a6878;
lbl_803d6030 = 0x803d6030;
w3d_format_8020c510 = 0x8020c510;
w3d_named_802b1510 = 0x802b1510;
SECTIONS {
  .text.d24l_choice_icon_802a62bc 0x802a62bc : { *(.text.d24l_choice_icon_802a62bc) }
  .rodata 0x803d60ec : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
