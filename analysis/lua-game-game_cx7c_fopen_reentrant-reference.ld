/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx7c_fopen_reentrant_802eb3c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx7c_close_802ec55c = 0x802ec55c;
cx7c_file_allocate_802eb284 = 0x802eb284;
cx7c_fseek_802eb704 = 0x802eb704;
cx7c_open_802f3328 = 0x802f3328;
cx7c_parse_mode_802f34c8 = 0x802f34c8;
cx7c_read_802ec424 = 0x802ec424;
cx7c_seek_802ec4f8 = 0x802ec4f8;
cx7c_write_802ec488 = 0x802ec488;
SECTIONS {
  .text.w3d_cx7c_fopen_reentrant_802eb3c8 0x802eb3c8 : { *(.text.w3d_cx7c_fopen_reentrant_802eb3c8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
