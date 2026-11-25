/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx13b_movie_async_read_complete_802e1360)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
read_802e128c = 0x802e128c;
SECTIONS {
  .text.w3d_cx13b_movie_async_read_complete_802e1360 0x802e1360 : { *(.text.w3d_cx13b_movie_async_read_complete_802e1360) }
  .sdata 0x804b190c (NOLOAD) : {
    . = 0x0; current_804b190c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
