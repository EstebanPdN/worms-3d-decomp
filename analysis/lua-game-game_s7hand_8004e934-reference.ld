/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8004e934)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8011AA98 = 0x8011aa98;
lbl_8040EA40 = 0x8040ea40;
SECTIONS {
  .text.w3d_auto_8004e934 0x8004e934 : { *(.text.w3d_auto_8004e934) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
