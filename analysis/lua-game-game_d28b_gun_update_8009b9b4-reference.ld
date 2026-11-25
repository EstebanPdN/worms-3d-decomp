/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28b_gun_update_8009b9b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80361860 = 0x80361860;
lbl_803618f0 = 0x803618f0;
lbl_80380078 = 0x80380078;
lbl_80380088 = 0x80380088;
lbl_803800e8 = 0x803800e8;
lbl_80380108 = 0x80380108;
lbl_8038011c = 0x8038011c;
lbl_80380138 = 0x80380138;
lbl_80380148 = 0x80380148;
lbl_80380150 = 0x80380150;
lbl_8038017c = 0x8038017c;
lbl_8040db38 = 0x8040db38;
w3d_alliance_count_80158f68 = 0x80158f68;
w3d_alliance_publish_80155b44 = 0x80155b44;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_bind_effect_8009d6d4 = 0x8009d6d4;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_camera_set_80035714 = 0x80035714;
w3d_cast_80341584 = 0x80341584;
w3d_cast_803426b4 = 0x803426b4;
w3d_clear_8009c758 = 0x8009c758;
w3d_context_80165254 = 0x80165254;
w3d_created_init_800c1620 = 0x800c1620;
w3d_finish_8015fd1c = 0x8015fd1c;
w3d_fire_8009c87c = 0x8009c87c;
w3d_log_80022e20 = 0x80022e20;
w3d_message_post_8016239c = 0x8016239c;
w3d_query_800fcea0 = 0x800fcea0;
w3d_rate_8009c850 = 0x8009c850;
w3d_read_800fc2f0 = 0x800fc2f0;
w3d_read_int_800fc230 = 0x800fc230;
w3d_sound_8009c0cc = 0x8009c0cc;
w3d_strcmp_802ef234 = 0x802ef234;
w3d_timer_is_one_8006e71c = 0x8006e71c;
w3d_value_80178c48 = 0x80178c48;
w3d_weapon_801797b4 = 0x801797b4;
w3d_wobble_8009ddc4 = 0x8009ddc4;
w3d_write_int_800fc43c = 0x800fc43c;
SECTIONS {
  .text.w3d_d28b_gun_update_8009b9b4 0x8009b9b4 : { *(.text.w3d_d28b_gun_update_8009b9b4) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; lbl_804aa8c8 = .;
    . = 0x320; lbl_804aabe8 = .;
    . = 0xb38; lbl_804ab400 = .;
    . = 0x3708; lbl_804adfd0 = .;
    . = 0x370c; lbl_804adfd4 = .;
    . = 0x3738; lbl_804ae000 = .;
    . = 0x3740; lbl_804ae008 = .;
    . = 0x3748; lbl_804ae010 = .;
    . = 0x3768; lbl_804ae030 = .;
    . = 0x3790; lbl_804ae058 = .;
    . = 0x37a0; lbl_804ae068 = .;
    . = 0x37b0; lbl_804ae078 = .;
    . = 0x37b8; lbl_804ae080 = .;
    . = 0x37d0; lbl_804ae098 = .;
    . = 0x6e8c; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
