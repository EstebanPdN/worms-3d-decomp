/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_rb_increment_80351ef8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80351f50 = 0x80351f50;
w3d_auto_80351fb0 = 0x80351fb0;
SECTIONS {
  .text.w3d_rb_increment_80351ef8 0x80351ef8 : { *(.text.w3d_rb_increment_80351ef8) }
  .text.w3d_rb_rebalance_for_erase_80352010 0x80352010 : { *(.text.w3d_rb_rebalance_for_erase_80352010) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
