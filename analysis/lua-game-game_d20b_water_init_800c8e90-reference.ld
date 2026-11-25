/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d20b_water_init_800c8e90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d20b_String_8020bb54PCc = 0x8020bb54;
cosf = 0x802e86d4;
d20b_as_value_80342a74 = 0x80342a74;
d20b_handle_load_8015adf4 = 0x8015adf4;
d20b_mesh_set_tint_80182178 = 0x80182178;
d20b_setting_find_800fc2b0 = 0x800fc2b0;
d20b_setting_object_800fc330 = 0x800fc330;
d20b_setting_read_800fc1b0 = 0x800fc1b0;
d20b_string_finish_8020c5c4 = 0x8020c5c4;
d20b_string_release_80341588 = 0x80341588;
d20b_tweak_name_80387b04 = 0x80387b04;
d20b_value_read_80178df0 = 0x80178df0;
d20b_water_build_800c9260 = 0x800c9260;
d20b_water_waves_800c96f0 = 0x800c96f0;
sinf = 0x802e88ac;
SECTIONS {
  .text.d20b_water_init_800c8e90 0x800c8e90 : { *(.text.d20b_water_init_800c8e90) }
  .rodata 0x80387b68 : { *(.rodata) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; d20b_game_804aaabc = .;
    . = 0x6cd8; d20b_water_804b1794 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
