/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d33a_airstrike_aim_trace_80032c84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d19c_nearest_sphere_801263fc = 0x801263fc;
d26d_camera_ray_hit_8015a46c = 0x8015a46c;
s19_active_team_value_80020834 = 0x80020834;
s8_property_read_800fc5dc = 0x800fc5dc;
s9_update_value_80178d28 = 0x80178d28;
s_up_vector_803732d4 = 0x803732d4;
sqrt_802e82c0 = 0x802e82c0;
w3d_auto_80178d1c = 0x80178d1c;
w3d_auto_80178df0 = 0x80178df0;
w3d_auto_80178ec4 = 0x80178ec4;
w3d_handle_member_query_801262c0 = 0x801262c0;
w3d_s20_set_vector_if_changed_80178fa4 = 0x80178fa4;
w3d_turns_get_active_actor = 0x80156f88;
SECTIONS {
  .text.w3d_d33a_airstrike_aim_trace_80032c84 0x80032c84 : { *(.text.w3d_d33a_airstrike_aim_trace_80032c84) }
  .rodata 0x803732e8 : { *(.rodata) }
  .sdata 0x804ab400 (NOLOAD) : {
    . = 0x0; g_turns_804ab400 = .;
    . = 0x6360; g_team_804b1760 = .;
    . = 0x6390; g_spacing_804b1790 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
