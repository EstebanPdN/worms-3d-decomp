/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__13Worm_80410e80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__12Str_803426b8 = 0x803426b8;
__13Base_8015fef0 = 0x8015fef0;
__15Handle_80126184 = 0x80126184;
_vt.13Worm_80410e80 = 0x80410e80;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.__13Worm_80410e80 0x80131d44 : { *(.text.__13Worm_80410e80) }
  .rodata 0x8039f0bc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
