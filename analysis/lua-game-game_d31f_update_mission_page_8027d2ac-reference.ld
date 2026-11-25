/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31f_update_mission_page_8027d2ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__14Cache_8015f704PCc = 0x8015f704;
__15String_803426b8 = 0x803426b8;
__15String_803426b8PCc = 0x8020bb54;
lbl_803ce9a0 = 0x803ce9a0;
lbl_803ceaa0 = 0x803ceaa0;
lbl_803ceab4 = 0x803ceab4;
lbl_803ceb0c = 0x803ceb0c;
lbl_803ceb18 = 0x803ceb18;
lbl_803ceb24 = 0x803ceb24;
lbl_803ceb30 = 0x803ceb30;
lbl_803ceb40 = 0x803ceb40;
lbl_803ceb44 = 0x803ceb44;
lbl_803ceb50 = 0x803ceb50;
lbl_803ceb60 = 0x803ceb60;
lbl_803ceb74 = 0x803ceb74;
lbl_803ceb80 = 0x803ceb80;
lbl_803ceb8c = 0x803ceb8c;
lbl_803ceba4 = 0x803ceba4;
lbl_803cebbc = 0x803cebbc;
lbl_803cebd4 = 0x803cebd4;
lbl_803cebe4 = 0x803cebe4;
lbl_803cebf4 = 0x803cebf4;
lbl_803cec04 = 0x803cec04;
lbl_803cec14 = 0x803cec14;
lbl_803cec24 = 0x803cec24;
lbl_803cec34 = 0x803cec34;
lbl_803cec44 = 0x803cec44;
lbl_803cec54 = 0x803cec54;
lbl_803cec64 = 0x803cec64;
s8_property_read_800fc550 = 0x800fc550;
s8_property_write_800fc43c = 0x800fc43c;
sol35e2_choose_string_8027befc = 0x8027befc;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_800fc230 = 0x800fc230;
w3d_auto_8015f558 = 0x8015f558;
w3d_auto_801797b4 = 0x801797b4;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80341584 = 0x80341584;
w3d_f7a_lookup_team_mission_80281924 = 0x80281924;
w3d_f7a_lookup_team_skill_80281ea4 = 0x80281ea4;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_r25b_category_count_8027be7c = 0x8027be7c;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_format = 0x8020c510;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
w3d_team_description_8027c018 = 0x8027c018;
w3d_team_mission_count_8027dacc = 0x8027dacc;
w3d_team_title_8027c24c = 0x8027c24c;
w3d_team_unlocked_8027dc5c = 0x8027dc5c;
SECTIONS {
  .text.d31f_update_mission_page_8027d2ac 0x8027d2ac : { *(.text.d31f_update_mission_page_8027d2ac) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
