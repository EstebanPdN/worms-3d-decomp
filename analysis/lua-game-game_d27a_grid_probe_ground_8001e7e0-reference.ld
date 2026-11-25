/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27a_grid_probe_ground_8001e7e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_hit_8043ae20 = 0x8043ae20;
g_hit_object_8043ae38 = 0x8043ae38;
s19_dispatch_indexed_800bd920 = 0x800bd920;
w3d_motion_slope_allowed = 0x8014c7fc;
w3d_trace_800b0824 = 0x800b0824;
SECTIONS {
  .text.w3d_d27a_grid_probe_ground_8001e7e0 0x8001e7e0 : { *(.text.w3d_d27a_grid_probe_ground_8001e7e0) }
  .rodata 0x8036b860 : { *(.rodata) }
  .sdata 0x804aa790 (NOLOAD) : {
    . = 0x0; g_margin_804aa790 = .;
    . = 0x6fd4; g_hit_time_804b1764 = .;
    . = 0x6ff4; g_hit_kind_804b1784 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
