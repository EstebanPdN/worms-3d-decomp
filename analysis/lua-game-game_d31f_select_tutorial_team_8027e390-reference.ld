/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31f_select_tutorial_team_8027e390)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__14Cache_8015f704PCc = 0x8015f704;
__15String_803426b8PCc = 0x8020bb54;
fn_8027d2ac = 0x8027d2ac;
lbl_803cea38 = 0x803cea38;
lbl_803cea44 = 0x803cea44;
lbl_803cea5c = 0x803cea5c;
lbl_803cea68 = 0x803cea68;
lbl_803ceaa0 = 0x803ceaa0;
lbl_803ceab4 = 0x803ceab4;
lbl_803ceac8 = 0x803ceac8;
lbl_803cecd0 = 0x803cecd0;
s8_property_read_800fc550 = 0x800fc550;
s8_property_write_800fc43c = 0x800fc43c;
strcmp = 0x802ef234;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_800fc230 = 0x800fc230;
w3d_auto_800fc2b0 = 0x800fc2b0;
w3d_auto_8015f558 = 0x8015f558;
w3d_auto_80179598 = 0x80179598;
w3d_auto_801797b4 = 0x801797b4;
w3d_barracks_team_available_80281c04 = 0x80281c04;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80341584 = 0x80341584;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_r25b_category_count_8027be7c = 0x8027be7c;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d31f_select_tutorial_team_8027e390 0x8027e390 : { *(.text.d31f_select_tutorial_team_8027e390) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
