/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_set_byte_from_float_801ed62c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__fixsfdi = 0x802f3cb8;
__fixunssfdi = 0x802f3c74;
SECTIONS {
  .text.w3d_set_byte_from_float_801ed62c 0x801ed62c : { *(.text.w3d_set_byte_from_float_801ed62c) }
  .text.w3d_set_long_from_float_801ed88c 0x801ed88c : { *(.text.w3d_set_long_from_float_801ed88c) }
  .text.w3d_set_ulong_from_float_801ed900 0x801ed900 : { *(.text.w3d_set_ulong_from_float_801ed900) }
  .text.w3d_set_float_member_801ed974 0x801ed974 : { *(.text.w3d_set_float_member_801ed974) }
  .text.w3d_set_float_member_801ed9cc 0x801ed9cc : { *(.text.w3d_set_float_member_801ed9cc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
