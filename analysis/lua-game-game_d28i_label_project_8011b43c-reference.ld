/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28i_label_project_8011b43c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
backing_8011bc28 = 0x8011bc28;
depth_8011ba08 = 0x8011ba08;
fromMat4_801f74d0 = 0x801f74d0;
invert_801f76e0 = 0x801f76e0;
SECTIONS {
  .text.d28i_label_project_8011b43c 0x8011b43c : { *(.text.d28i_label_project_8011b43c) }
  .rodata 0x8039af54 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; globals_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
