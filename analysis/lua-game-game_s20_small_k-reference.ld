/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_dispatch_indexed_801a4a90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_dispatch_indexed_801a4a90 0x801a4a90 : { *(.text.w3d_s20_dispatch_indexed_801a4a90) }
  .text.w3d_s20_dispatch_indexed_801a4aec 0x801a4aec : { *(.text.w3d_s20_dispatch_indexed_801a4aec) }
  .text.w3d_s20_read_row_801d6888 0x801d6888 : { *(.text.w3d_s20_read_row_801d6888) }
  .text.w3d_s20_read_column_801d68e0 0x801d68e0 : { *(.text.w3d_s20_read_column_801d68e0) }
  .text.w3d_s20_write_pixel_801d6940 0x801d6940 : { *(.text.w3d_s20_write_pixel_801d6940) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
