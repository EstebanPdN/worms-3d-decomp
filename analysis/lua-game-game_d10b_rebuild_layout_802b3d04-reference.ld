/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d10b_rebuild_layout_802b3d04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d10b_apply_layout_802b38d4 = 0x802b38d4;
d10b_build_layout_802b3148 = 0x802b3148;
SECTIONS {
  .text.d10b_rebuild_layout_802b3d04 0x802b3d04 : { *(.text.d10b_rebuild_layout_802b3d04) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
