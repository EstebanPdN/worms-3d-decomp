/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_worm_damage_80148a40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._11d24d_Handle = 0x80178474;
d24d_arena_alloc_801613f0 = 0x801613f0;
d24d_clear_links_8014df84 = 0x8014df84;
d24d_display_803426b4 = 0x803426b4;
d24d_display_value_80178c48 = 0x80178c48;
d24d_has_active_801510c4 = 0x801510c4;
d24d_message_id_8015f5a0 = 0x8015f5a0;
d24d_message_init_800a82f0 = 0x800a82f0;
d24d_message_post_8016239c = 0x8016239c;
d24d_message_vtable_8040db38 = 0x8040db38;
d24d_mode_is_four_80153f38 = 0x80153f38;
d24d_owner_matches_8014c488 = 0x8014c488;
d24d_post_alliance_801533a4 = 0x801533a4;
d24d_special_action_80148ef0 = 0x80148ef0;
d24d_special_flag_8014e9b4 = 0x8014e9b4;
d24d_stats_view_801797b4 = 0x801797b4;
d24d_worm_handle_800fc710 = 0x800fc710;
d24d_worm_info_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.d24d_worm_damage_80148a40 0x80148a40 : { *(.text.d24d_worm_damage_80148a40) }
  .sdata 0x804afb60 (NOLOAD) : {
    . = 0x0; d24d_hit_key_804afb60 = .;
    . = 0x8; d24d_owner_key_804afb68 = .;
    . = 0x1bf4; d24d_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
