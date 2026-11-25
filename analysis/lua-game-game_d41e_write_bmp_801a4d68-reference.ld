/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41e_write_bmp_801a4d68)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__builtin_vec_delete = 0x801fe240;
__builtin_vec_new = 0x801fe220;
memcpy = 0x802eee50;
SECTIONS {
  .text.w3d_d41e_write_bmp_801a4d68 0x801a4d68 : { *(.text.w3d_d41e_write_bmp_801a4d68) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
