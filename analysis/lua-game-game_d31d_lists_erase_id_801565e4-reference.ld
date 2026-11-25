/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31d_lists_erase_id_801565e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memcpy = 0x802eee50;
SECTIONS {
  .text.w3d_d31d_lists_erase_id_801565e4 0x801565e4 : { *(.text.w3d_d31d_lists_erase_id_801565e4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
