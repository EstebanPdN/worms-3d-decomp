/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9c_buffered_seek_802eb704)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx9c_flush_802eb084 = 0x802eb084;
cx9c_make_buffer_802ebee4 = 0x802ebee4;
cx9c_refill_802ec088 = 0x802ec088;
cx9c_seek_file_802ec4f8 = 0x802ec4f8;
cx9c_stat_file_802f3278 = 0x802f3278;
cx9c_stdio_init_802eb1d4 = 0x802eb1d4;
SECTIONS {
  .text.w3d_cx9c_buffered_seek_802eb704 0x802eb704 : { *(.text.w3d_cx9c_buffered_seek_802eb704) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; cx9c_reent_804ac570 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
