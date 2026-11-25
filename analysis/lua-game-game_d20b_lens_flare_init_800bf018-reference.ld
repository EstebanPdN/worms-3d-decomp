/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d20b_lens_flare_init_800bf018)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d20b_String_8020bb54PCc = 0x8020bb54;
d20b_arrays_colour_80189760 = 0x80189760;
d20b_arrays_kind_80189828 = 0x80189828;
d20b_arrays_offset_80189518 = 0x80189518;
d20b_arrays_reserve_8018920c = 0x8018920c;
d20b_arrays_resize_80189450 = 0x80189450;
d20b_arrays_size_8018963c = 0x8018963c;
d20b_arrays_uv0_80189884 = 0x80189884;
d20b_arrays_uv1_801898e0 = 0x801898e0;
d20b_as_arrays_8034380c = 0x8034380c;
d20b_as_config_80341584 = 0x80341584;
d20b_cached_message_id_8015f5a0 = 0x8015f5a0;
d20b_engine_context_80165254 = 0x80165254;
d20b_fe_lens_flares_80382e34 = 0x80382e34;
d20b_flare_corners_80382e84 = 0x80382e84;
d20b_flare_params_801797b4 = 0x801797b4;
d20b_flare_settings_803f4cb8 = 0x803f4cb8;
d20b_handle_construct_801261bc = 0x801261bc;
d20b_handle_load_8015adf4 = 0x8015adf4;
d20b_handle_set_layer_80126308 = 0x80126308;
d20b_heap_allocate_802098d8 = 0x802098d8;
d20b_lens_flares_80382e28 = 0x80382e28;
d20b_setting_read_800fc1b0 = 0x800fc1b0;
d20b_string_finish_8020c5c4 = 0x8020c5c4;
d20b_string_release_80341588 = 0x80341588;
d20b_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.d20b_lens_flare_init_800bf018 0x800bf018 : { *(.text.d20b_lens_flare_init_800bf018) }
  .rodata 0x80382e44 : { *(.rodata) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; d20b_game_804aaabc = .;
    . = 0x3b50; d20b_message_cache_804ae60c = .;
    . = 0x4b00; d20b_handle_heap_804af5bc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
