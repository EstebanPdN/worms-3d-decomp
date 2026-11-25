/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30k_gauge_bar_layout_8026807c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803cb724 = 0x803cb724;
SECTIONS {
  .text.w3d_d30k_gauge_bar_layout_8026807c 0x8026807c : { *(.text.w3d_d30k_gauge_bar_layout_8026807c) }
  .rodata 0x803cb728 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
