/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32a_day_cycle_tick_80027814)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
d30j_remove_node_children_80164cec = 0x80164cec;
fn_80164514 = 0x80164514;
g_key_8040f7c8 = 0x8040f7c8;
g_key_8040f818 = 0x8040f818;
g_type_803667a8 = 0x803667a8;
strcmp = 0x802ef234;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_800fc2b0 = 0x800fc2b0;
w3d_auto_8015fc58 = 0x8015fc58;
w3d_auto_801797b4 = 0x801797b4;
w3d_cached_message_id = 0x8015f5a0;
w3d_cx9c_cosf_802e86d4 = 0x802e86d4;
w3d_cx9c_sinf_802e88ac = 0x802e88ac;
w3d_empty_80341584 = 0x80341584;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_format = 0x8020c510;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_d32a_day_cycle_tick_80027814 0x80027814 : { *(.text.w3d_d32a_day_cycle_tick_80027814) }
  .rodata 0x8036cc94 : { *(.rodata) }
  .sdata 0x804aa810 (NOLOAD) : {
    . = 0x0; g_time_804aa810 = .;
    . = 0x4; g_prev_804aa814 = .;
    . = 0x8; g_cur_804aa818 = .;
    . = 0xc; g_phase_804aa81c = .;
    . = 0x23b4; g_id_804acbc4 = .;
    . = 0x23bc; g_id_804acbcc = .;
    . = 0x23c4; g_id_804acbd4 = .;
    . = 0x6f44; g_arena_804b1754 = .;
    . = 0x6f78; g_engine_804b1788 = .;
    . = 0x6f7c; g_hub_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
