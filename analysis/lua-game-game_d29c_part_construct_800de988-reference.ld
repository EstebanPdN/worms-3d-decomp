/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29c_part_construct_800de988)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
empty_804b06a0 = 0x804b06a0;
release_8020bb2c = 0x8020bb2c;
string_default_803426b8 = 0x803426b8;
vt_8040ff68 = 0x8040ff68;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d29c_part_construct_800de988 0x800de988 : { *(.text.d29c_part_construct_800de988) }
  .rodata 0x80389c14 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
