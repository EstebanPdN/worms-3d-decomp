/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_hit_expanded_802b6af0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802b15e0 = 0x802b15e0;
fn_802b22e4 = 0x802b22e4;
value_803d800c = 0x803d800c;
value_803d8010 = 0x803d8010;
value_803d8014 = 0x803d8014;
SECTIONS {
  .text.w3d_hit_expanded_802b6af0 0x802b6af0 : { *(.text.w3d_hit_expanded_802b6af0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
