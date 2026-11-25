/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc24a_planner_radial_influence_800167ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc24a_sqrt_802e82c0 = 0x802e82c0;
cc24a_zero_8036a684 = 0x8036a684;
SECTIONS {
  .text.cc24a_planner_radial_influence_800167ac 0x800167ac : { *(.text.cc24a_planner_radial_influence_800167ac) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; cc24a_config_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
