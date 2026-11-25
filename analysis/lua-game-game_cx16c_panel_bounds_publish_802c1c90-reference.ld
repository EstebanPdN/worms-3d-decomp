/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16c_panel_bounds_publish_802c1c90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx16c_bounds_max_804668dc = 0x804668dc;
cx16c_bounds_min_804668d0 = 0x804668d0;
cx16c_held_close_8015fd1c = 0x8015fd1c;
SECTIONS {
  .text.w3d_cx16c_panel_bounds_publish_802c1c90 0x802c1c90 : { *(.text.w3d_cx16c_panel_bounds_publish_802c1c90) }
  .sdata 0x804abb60 (NOLOAD) : {
    . = 0x0; cx16c_live_804abb60 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
