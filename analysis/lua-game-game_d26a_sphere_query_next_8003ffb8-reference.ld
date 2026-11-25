/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26a_sphere_query_next_8003ffb8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_center_80427408 = 0x80427408;
g_delta_80427444 = 0x80427444;
g_hit_80427450 = 0x80427450;
g_items_804273ec = 0x804273ec;
SECTIONS {
  .text.w3d_d26a_sphere_query_next_8003ffb8 0x8003ffb8 : { *(.text.w3d_d26a_sphere_query_next_8003ffb8) }
  .sdata 0x804aa950 (NOLOAD) : {
    . = 0x0; g_ignore_804aa950 = .;
    . = 0x4; g_mask_804aa954 = .;
    . = 0xc; g_cursor_804aa95c = .;
    . = 0xe; g_current_804aa95e = .;
    . = 0x10; g_owner_804aa960 = .;
    . = 0x6e68; g_radius_804b17b8 = .;
    . = 0x6e80; g_dist_804b17d0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
