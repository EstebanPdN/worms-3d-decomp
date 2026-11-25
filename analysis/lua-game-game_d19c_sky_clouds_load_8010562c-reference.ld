/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19c_sky_clouds_load_8010562c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d19c_String_8020bb54PCc = 0x8020bb54;
d19c_as_node_80343584 = 0x80343584;
d19c_check_control_8018179c = 0x8018179c;
d19c_handle_load_8015adf4 = 0x8015adf4;
d19c_owner_value_80182150 = 0x80182150;
d19c_play_clip_80181640 = 0x80181640;
d19c_sky_bind_clouds_80106300 = 0x80106300;
d19c_sky_clouds_803fce18 = 0x803fce18;
d19c_sky_layer_position_8044b67c = 0x8044b67c;
d19c_string_finish_8020c5c4 = 0x8020c5c4;
d19c_string_release_80341588 = 0x80341588;
strcmp = 0x802ef234;
SECTIONS {
  .text.d19c_sky_clouds_load_8010562c 0x8010562c : { *(.text.d19c_sky_clouds_load_8010562c) }
  .rodata 0x80399898 : { *(.rodata) }
  .sdata 0x804aaf9c (NOLOAD) : {
    . = 0x0; d19c_cloud_loop_clip_804aaf9c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
