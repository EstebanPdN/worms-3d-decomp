/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc27a_planner_airstrike_direction_800219b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc27a_air_8036c0c8 = 0x8036c0c8;
cc27a_dir_8036c0a0 = 0x8036c0a0;
cc27a_property_800fc5dc = 0x800fc5dc;
cc27a_sqrt_802e82c0 = 0x802e82c0;
cc27a_up_8036c0b4 = 0x8036c0b4;
SECTIONS {
  .text.cc27a_planner_airstrike_direction_800219b8 0x800219b8 : { *(.text.cc27a_planner_airstrike_direction_800219b8) }
  .rodata 0x8036c0dc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
