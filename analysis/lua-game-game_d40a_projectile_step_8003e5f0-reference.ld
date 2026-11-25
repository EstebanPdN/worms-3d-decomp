/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40a_projectile_step_8003e5f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
arena_801613f0 = 0x801613f0;
compute_800bd920 = 0x800bd920;
g_normal_8043ae38 = 0x8043ae38;
g_point_8043ae20 = 0x8043ae20;
hit_delta_800418ac = 0x800418ac;
impulse_8003ebdc = 0x8003ebdc;
item_8003f240 = 0x8003f240;
message_id_8015f5a0 = 0x8015f5a0;
nearest_sphere_801263fc = 0x801263fc;
post_8016239c = 0x8016239c;
reflect_8003ee4c = 0x8003ee4c;
set_bounds_80126278 = 0x80126278;
sqrt_802e82c0 = 0x802e82c0;
w3d_message_table_8040db38 = 0x8040db38;
w3d_trace_800b0824 = 0x800b0824;
w3d_value_80178df0 = 0x80178df0;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_d40a_projectile_step_8003e5f0 0x8003e5f0 : { *(.text.w3d_d40a_projectile_step_8003e5f0) }
  .rodata 0x80374658 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; g_item_804aa95e = .;
    . = 0x284e; w3d_message_804ad1ac = .;
    . = 0x6df6; w3d_arena_804b1754 = .;
    . = 0x6e06; g_hit_804b1764 = .;
    . = 0x6e26; traceReady_804b1784 = .;
    . = 0x6e32; g_steps_804b1790 = .;
    . = 0x6e46; g_dt_804b17a4 = .;
    . = 0x6e4a; g_colour_804b17a8 = .;
    . = 0x6e4e; g_colour_804b17ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
