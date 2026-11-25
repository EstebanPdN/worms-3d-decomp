/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d44l_parts_layout_802a64a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802a6ce8 = 0x802a6ce8;
SECTIONS {
  .text.d44l_parts_layout_802a64a8 0x802a64a8 : { *(.text.d44l_parts_layout_802a64a8) }
  .rodata 0x803d6108 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
