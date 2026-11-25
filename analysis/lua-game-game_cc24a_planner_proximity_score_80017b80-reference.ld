/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc24a_planner_proximity_score_80017b80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc24a_factor_80019fb4 = 0x80019fb4;
cc24a_origin_8041d3a0 = 0x8041d3a0;
cc24a_reset_80017a04 = 0x80017a04;
cc24a_sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.cc24a_planner_proximity_score_80017b80 0x80017b80 : { *(.text.cc24a_planner_proximity_score_80017b80) }
  .rodata 0x8036a82c : { *(.rodata) }
  .sdata 0x804aa6c0 (NOLOAD) : {
    . = 0x0; cc24a_owner_804aa6c0 = .;
    . = 0x18; cc24a_config_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
