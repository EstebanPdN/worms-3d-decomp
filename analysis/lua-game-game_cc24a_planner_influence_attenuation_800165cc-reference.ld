/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc24a_planner_influence_attenuation_800165cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc24a_influence_800167ac = 0x800167ac;
cc24a_origin_8041d3a0 = 0x8041d3a0;
SECTIONS {
  .text.cc24a_planner_influence_attenuation_800165cc 0x800165cc : { *(.text.cc24a_planner_influence_attenuation_800165cc) }
  .rodata 0x8036a674 : { *(.rodata) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; cc24a_config_804aa6d8 = .;
    . = 0x24; cc24a_entries_804aa6fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
