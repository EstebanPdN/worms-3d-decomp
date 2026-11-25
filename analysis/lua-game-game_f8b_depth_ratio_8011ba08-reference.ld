/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f8b_depth_ratio_8011ba08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
read_80178df0 = 0x80178df0;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.f8b_depth_ratio_8011ba08 0x8011ba08 : { *(.text.f8b_depth_ratio_8011ba08) }
  .rodata 0x8039af5c : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
