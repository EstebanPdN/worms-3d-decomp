/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_flag_set_801d994c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_flag_set_801d994c 0x801d994c : { *(.text.w3d_flag_set_801d994c) }
  .text.w3d_flag_test_801d9984 0x801d9984 : { *(.text.w3d_flag_test_801d9984) }
  .text.w3d_flag_set_801e8390 0x801e8390 : { *(.text.w3d_flag_set_801e8390) }
  .text.w3d_flag_test_801e83c8 0x801e83c8 : { *(.text.w3d_flag_test_801e83c8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
