/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_array_write_8024b8dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_array_reserve_801ef048 = 0x801ef048;
SECTIONS {
  .text.w3d_array_write_8024b8dc 0x8024b8dc : { *(.text.w3d_array_write_8024b8dc) }
  .text.w3d_array_write_8024b998 0x8024b998 : { *(.text.w3d_array_write_8024b998) }
  .text.w3d_array_write_80251064 0x80251064 : { *(.text.w3d_array_write_80251064) }
  .text.w3d_array_write_802514f8 0x802514f8 : { *(.text.w3d_array_write_802514f8) }
  .text.w3d_array_write_802515b4 0x802515b4 : { *(.text.w3d_array_write_802515b4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
