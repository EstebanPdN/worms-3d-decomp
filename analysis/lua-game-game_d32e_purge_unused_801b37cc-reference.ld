/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32e_purge_unused_801b37cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
f4c_erase_80210dd8 = 0x80210dd8;
memmove = 0x802eeef4;
w3d_d25e_release_lists_801b4140 = 0x801b4140;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_d32e_purge_unused_801b37cc 0x801b37cc : { *(.text.w3d_d32e_purge_unused_801b37cc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
