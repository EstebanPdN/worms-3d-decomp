/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26a_ray_query_next_800400f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_delta_80427444 = 0x80427444;
g_dir_80427414 = 0x80427414;
g_four_8037473c = 0x8037473c;
g_items_804273ec = 0x804273ec;
g_origin_80427408 = 0x80427408;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.w3d_d26a_ray_query_next_800400f0 0x800400f0 : { *(.text.w3d_d26a_ray_query_next_800400f0) }
  .rodata 0x80374740 : { *(.rodata) }
  .sdata 0x804aa950 (NOLOAD) : {
    . = 0x0; g_ignore_804aa950 = .;
    . = 0x4; g_mask_804aa954 = .;
    . = 0xc; g_cursor_804aa95c = .;
    . = 0xe; g_current_804aa95e = .;
    . = 0x10; g_owner_804aa960 = .;
    . = 0x14; g_past_804aa964 = .;
    . = 0x6e40; g_ti_804b1790 = .;
    . = 0x6e54; g_t_804b17a4 = .;
    . = 0x6e68; g_radius_804b17b8 = .;
    . = 0x6e6c; g_limit_804b17bc = .;
    . = 0x6e70; g_a_804b17c0 = .;
    . = 0x6e80; g_dist_804b17d0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
