/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc36a_transform_cache_800b8cf0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__21cc36a_Vector_80343740 = 0x80343740;
cc36a_combine_801f740c = 0x801f740c;
cc36a_inverse_801f76e0 = 0x801f76e0;
SECTIONS {
  .text.cc36a_transform_cache_800b8cf0 0x800b8cf0 : { *(.text.cc36a_transform_cache_800b8cf0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
