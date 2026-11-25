/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc24a_planner_damage_score_80011950)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc24a_death_name_8036a358 = 0x8036a358;
cc24a_exposure_8000b7dc = 0x8000b7dc;
cc24a_flag_factor_8036a380 = 0x8036a380;
cc24a_float_property_800fc270 = 0x800fc270;
cc24a_reset_8000b2f8 = 0x8000b2f8;
cc24a_sum_8000b4c4 = 0x8000b4c4;
SECTIONS {
  .text.cc24a_planner_damage_score_80011950 0x80011950 : { *(.text.cc24a_planner_damage_score_80011950) }
  .rodata 0x8036a378 : { *(.rodata) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; cc24a_config_804aa6d8 = .;
    . = 0x10; cc24a_index_804aa6e8 = .;
    . = 0x78; cc24a_entries_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
