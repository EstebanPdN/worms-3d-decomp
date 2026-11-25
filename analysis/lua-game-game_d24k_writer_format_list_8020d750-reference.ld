/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24k_writer_format_list_8020d750)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
temp_alloc_801fe0b8 = 0x801fe0b8;
temp_release_801fe160 = 0x801fe160;
vsnprintf_802ed63c = 0x802ed63c;
SECTIONS {
  .text.w3d_d24k_writer_format_list_8020d750 0x8020d750 : { *(.text.w3d_d24k_writer_format_list_8020d750) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
