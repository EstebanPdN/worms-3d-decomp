/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d18c_sky_moon_load_801058f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d18c_String_8020bb54PCc = 0x8020bb54;
d18c_arctic_night_8039971c = 0x8039971c;
d18c_as_node_80343584 = 0x80343584;
d18c_check_control_8018179c = 0x8018179c;
d18c_handle_load_8015adf4 = 0x8015adf4;
d18c_moon_position_8044b67c = 0x8044b67c;
d18c_play_clip_80181640 = 0x80181640;
d18c_sky_clouds_803fce18 = 0x803fce18;
d18c_sky_moons_803fce58 = 0x803fce58;
d18c_string_finish_8020c5c4 = 0x8020c5c4;
d18c_string_release_80341588 = 0x80341588;
strcmp = 0x802ef234;
SECTIONS {
  .text.d18c_sky_moon_load_801058f0 0x801058f0 : { *(.text.d18c_sky_moon_load_801058f0) }
  .rodata 0x803998a0 : { *(.rodata) }
  .sdata 0x804aaf9c (NOLOAD) : {
    . = 0x0; d18c_borealis_clip_804aaf9c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
