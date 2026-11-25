/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29g_energy_bars_refresh_80065ce0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
f7b_interpolate_800647cc = 0x800647cc;
s8_index_query_800fc6dc = 0x800fc6dc;
w3d_auto_8006456c = 0x8006456c;
w3d_auto_80064d88 = 0x80064d88;
w3d_auto_80065b5c = 0x80065b5c;
w3d_auto_80065bf8 = 0x80065bf8;
w3d_auto_80178c48 = 0x80178c48;
w3d_auto_80178df0 = 0x80178df0;
w3d_cx15a_approach_level_80064950 = 0x80064950;
w3d_d24g_energy_bar_set_team_80064384 = 0x80064384;
w3d_empty_803426b4 = 0x803426b4;
w3d_fn_800664f8 = 0x800664f8;
w3d_k10a_team_flags_apply_80064dcc = 0x80064dcc;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_timed_state_resource_mode_80064274 = 0x80064274;
w3d_timed_state_set_mode_80064190 = 0x80064190;
w3d_timed_state_set_rate_80064548 = 0x80064548;
SECTIONS {
  .text.w3d_d29g_energy_bars_refresh_80065ce0 0x80065ce0 : { *(.text.w3d_d29g_energy_bars_refresh_80065ce0) }
  .rodata 0x80379e80 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
