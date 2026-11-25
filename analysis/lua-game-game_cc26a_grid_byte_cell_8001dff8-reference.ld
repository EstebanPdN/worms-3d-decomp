/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc26a_grid_byte_cell_8001dff8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc26a_find_8001df1c = 0x8001df1c;
SECTIONS {
  .text.cc26a_grid_byte_cell_8001dff8 0x8001dff8 : { *(.text.cc26a_grid_byte_cell_8001dff8) }
  .sdata 0x804ac914 (NOLOAD) : {
    . = 0x0; cc26a_fallback_804ac914 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
