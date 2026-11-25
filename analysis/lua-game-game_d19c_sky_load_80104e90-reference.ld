/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19c_sky_load_80104e90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d19c_String_8020bb54PCc = 0x8020bb54;
d19c_as_node_80343584 = 0x80343584;
d19c_find_bone_80181e3c = 0x80181e3c;
d19c_handle_load_8015adf4 = 0x8015adf4;
d19c_light_service_8040f858 = 0x8040f858;
d19c_owner_value_80182150 = 0x80182150;
d19c_point_init_80343740 = 0x80343740;
d19c_scene_add_light_80164514 = 0x80164514;
d19c_service_find_8020b680 = 0x8020b680;
d19c_settings_read_800fc2b0 = 0x800fc2b0;
d19c_sky_bind_clouds_80106300 = 0x80106300;
d19c_sky_cloud_speeds_803fce40 = 0x803fce40;
d19c_sky_clouds_load_8010562c = 0x8010562c;
d19c_sky_flags_80399a30 = 0x80399a30;
d19c_sky_init_80105164 = 0x80105164;
d19c_sky_layer_position_8044b67c = 0x8044b67c;
d19c_sky_moon_load_801058f0 = 0x801058f0;
d19c_string_finish_8020c5c4 = 0x8020c5c4;
d19c_string_release_80341588 = 0x80341588;
d19c_sun_position_8044b688 = 0x8044b688;
strcmp = 0x802ef234;
SECTIONS {
  .text.d19c_sky_load_80104e90 0x80104e90 : { *(.text.d19c_sky_load_80104e90) }
  .rodata 0x80399844 : { *(.rodata) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; d19c_light_scene_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
