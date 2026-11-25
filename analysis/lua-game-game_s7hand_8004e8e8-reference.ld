/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8004e8e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8011A918 = 0x8011a918;
lbl_8040EA40 = 0x8040ea40;
SECTIONS {
  .text.w3d_auto_8004e8e8 0x8004e8e8 : { *(.text.w3d_auto_8004e8e8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
