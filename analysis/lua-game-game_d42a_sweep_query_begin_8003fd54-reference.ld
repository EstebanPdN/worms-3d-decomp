/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d42a_sweep_query_begin_8003fd54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_axis_80427420 = 0x80427420;
g_dir_80427414 = 0x80427414;
g_items_804273ec = 0x804273ec;
g_normal_8042742c = 0x8042742c;
g_origin_80427408 = 0x80427408;
g_side_80427438 = 0x80427438;
sqrt_802e82c0 = 0x802e82c0;
w3d_d26a_ray_query_next_800400f0 = 0x800400f0;
w3d_d26a_sphere_query_next_8003ffb8 = 0x8003ffb8;
w3d_fn_800412d8 = 0x800412d8;
SECTIONS {
  .text.w3d_d42a_sweep_query_begin_8003fd54 0x8003fd54 : { *(.text.w3d_d42a_sweep_query_begin_8003fd54) }
  .rodata 0x80374734 : { *(.rodata) }
  .sdata 0x804aa950 (NOLOAD) : {
    . = 0x0; g_ignore_804aa950 = .;
    . = 0x4; g_mask_804aa954 = .;
    . = 0x8; g_active_804aa958 = .;
    . = 0xc; g_cursor_804aa95c = .;
    . = 0x10; g_owner_804aa960 = .;
    . = 0x6e40; g_ti_804b1790 = .;
    . = 0x6e60; g_radsq_804b17b0 = .;
    . = 0x6e64; g_next_804b17b4 = .;
    . = 0x6e68; g_radius_804b17b8 = .;
    . = 0x6e6c; g_limit_804b17bc = .;
    . = 0x6e70; g_a_804b17c0 = .;
    . = 0x6e74; g_b_804b17c4 = .;
    . = 0x6e78; g_c_804b17c8 = .;
    . = 0x6e7c; g_len_804b17cc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
