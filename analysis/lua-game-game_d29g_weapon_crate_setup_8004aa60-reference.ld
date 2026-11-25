/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29g_weapon_crate_setup_8004aa60)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s_contents_80376fa8 = 0x80376fa8;
s_error_80377008 = 0x80377008;
s_int_80377024 = 0x80377024;
s_unrecognised_80376fe4 = 0x80376fe4;
s_x_80377028 = 0x80377028;
sprintf = 0x802ec254;
strcmp = 0x802ef234;
w3d_auto_800fc2b0 = 0x800fc2b0;
w3d_auto_800fc330 = 0x800fc330;
w3d_cx13b_utf8_encode_16_8018b2b0 = 0x8018b2b0;
w3d_fn_8004a930 = 0x8004a930;
w3d_fn_8004b3f0 = 0x8004b3f0;
w3d_string_append = 0x8020bf2c;
w3d_string_assign = 0x8020bd38;
weapon_names_803eb63c = 0x803eb63c;
SECTIONS {
  .text.w3d_d29g_weapon_crate_setup_8004aa60 0x8004aa60 : { *(.text.w3d_d29g_weapon_crate_setup_8004aa60) }
  .rodata 0x8037702c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
