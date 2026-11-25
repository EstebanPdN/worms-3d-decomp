/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__sinit)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_extra_files_8047d7d0 = 0x8047d7d0;
w3d_extra_glue_8047db90 = 0x8047db90;
w3d_newlib_std_802eb178 = 0x802eb178;
w3d_stream_walk_all_802eb4e4 = 0x802eb4e4;
SECTIONS {
  .text.__sinit 0x802eb1d4 : { *(.text.__sinit) }
  .text.__sflags 0x802f34c8 : { *(.text.__sflags) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
