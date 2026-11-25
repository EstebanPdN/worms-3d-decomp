/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_fire_punch_jump)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800ac238 = 0x800ac238;
w3d_auto_801610a0 = 0x801610a0;
w3d_cached_message_id = 0x8015f5a0;
w3d_f32_803a1650 = 0x803a1650;
w3d_f32_803a1654 = 0x803a1654;
w3d_f32_803a1690 = 0x803a1690;
w3d_f32_803a16b8 = 0x803a16b8;
w3d_f32_803a16bc = 0x803a16bc;
w3d_fn_80022e20 = 0x80022e20;
w3d_fn_8003a264 = 0x8003a264;
w3d_fn_800cfc98 = 0x800cfc98;
w3d_fn_800fc6dc = 0x800fc6dc;
w3d_fn_801492ec = 0x801492ec;
w3d_fn_8014c488 = 0x8014c488;
w3d_fn_80153dfc = 0x80153dfc;
w3d_fn_801613f0 = 0x801613f0;
w3d_fn_80164fc8 = 0x80164fc8;
w3d_message_int_init = 0x800a82f0;
w3d_message_post_current = 0x8016239c;
w3d_message_type_8040db38 = 0x8040db38;
w3d_str_803a0e2c = 0x803a0e2c;
w3d_str_803a163c = 0x803a163c;
w3d_type_80361860 = 0x80361860;
w3d_type_803618f0 = 0x803618f0;
SECTIONS {
  .text.w3d_actor_fire_punch_jump 0x8014d65c : { *(.text.w3d_actor_fire_punch_jump) }
  .text.w3d_actor_link_c_state 0x8014dc04 : { *(.text.w3d_actor_link_c_state) }
  .text.w3d_actor_link_b_query 0x8014dc60 : { *(.text.w3d_actor_link_b_query) }
  .text.w3d_actor_link_b_active 0x8014dcbc : { *(.text.w3d_actor_link_b_active) }
  .text.w3d_actor_post_pair_query 0x8014de20 : { *(.text.w3d_actor_post_pair_query) }
  .text.w3d_actor_link_a_flag 0x8014de70 : { *(.text.w3d_actor_link_a_flag) }
  .text.w3d_actor_link_a_state 0x8014decc : { *(.text.w3d_actor_link_a_state) }
  .text.w3d_actor_link_a_second_flag 0x8014df28 : { *(.text.w3d_actor_link_a_second_flag) }
  .text.w3d_actor_clear_links 0x8014df84 : { *(.text.w3d_actor_clear_links) }
  .text.w3d_actor_timed_value 0x8014e104 : { *(.text.w3d_actor_timed_value) }
  .text.w3d_actor_link_c_falling_message 0x8014e3d4 : { *(.text.w3d_actor_link_c_falling_message) }
  .text.w3d_actor_link_a_falling_step 0x8014e44c : { *(.text.w3d_actor_link_a_falling_step) }
  .text.w3d_actor_other_entity_reaction 0x8014e774 : { *(.text.w3d_actor_other_entity_reaction) }
  .sdata 0x804afbd0 (NOLOAD) : {
    . = 0x0; w3d_cached_804afbd0 = .;
    . = 0x20; w3d_cached_804afbf0 = .;
    . = 0x28; w3d_cached_804afbf8 = .;
    . = 0x48; w3d_cached_804afc18 = .;
    . = 0x50; w3d_cached_804afc20 = .;
    . = 0x60; w3d_cached_804afc30 = .;
    . = 0x1b84; w3d_global_804b1754 = .;
    . = 0x1bd0; w3d_message_result_804b17a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
