/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc24a_planner_bomber_score_8000e0ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc24a_damage_8000e058 = 0x8000e058;
cc24a_distance_8000b5f4 = 0x8000b5f4;
cc24a_duration_name_80369f58 = 0x80369f58;
cc24a_exposure_8000b7dc = 0x8000b7dc;
cc24a_float_property_800fc270 = 0x800fc270;
cc24a_radius_8000e094 = 0x8000e094;
cc24a_range_8000e0bc = 0x8000e0bc;
cc24a_reset_8000b2f8 = 0x8000b2f8;
cc24a_speed_name_80369f44 = 0x80369f44;
cc24a_sum_8000b4c4 = 0x8000b4c4;
cc24a_uint_property_800fc230 = 0x800fc230;
SECTIONS {
  .text.cc24a_planner_bomber_score_8000e0ec 0x8000e0ec : { *(.text.cc24a_planner_bomber_score_8000e0ec) }
  .rodata 0x80369f70 : { *(.rodata) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; cc24a_config_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
