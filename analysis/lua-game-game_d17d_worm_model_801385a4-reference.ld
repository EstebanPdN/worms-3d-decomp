/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d17d_worm_refresh_model_801385a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__11d17d_StringPCc = 0x8020bb54;
d17d_check_control_8018179c = 0x8018179c;
d17d_handle_load_8015adf4 = 0x8015adf4;
d17d_mesh_of_80343584 = 0x80343584;
d17d_mesh_set_resource_value_80182410 = 0x80182410;
d17d_mode_enter_8013ef98 = 0x8013ef98;
d17d_mode_enter_8013efe8 = 0x8013efe8;
d17d_play_named_801359ec = 0x801359ec;
d17d_resource_lookup_800fc330 = 0x800fc330;
d17d_resource_table_803eb63c = 0x803eb63c;
d17d_string_finish_8020c5c4 = 0x8020c5c4;
d17d_string_header_80341884 = 0x80341884;
d17d_string_init_8020c5c0 = 0x8020c5c0;
d17d_string_release_80341588 = 0x80341588;
d17d_worm_data_800fc6dc = 0x800fc6dc;
s9_release_actor_inner_8013e458 = 0x8013e458;
strcmp = 0x802ef234;
SECTIONS {
  .text.d17d_worm_refresh_model_801385a4 0x801385a4 : { *(.text.d17d_worm_refresh_model_801385a4) }
  .rodata 0x8039f59c : { *(.rodata) }
  .sdata 0x804ab328 (NOLOAD) : {
    . = 0x0; d17d_attach_id_804ab328 = .;
    . = 0x4; d17d_attach_id_804ab32c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
