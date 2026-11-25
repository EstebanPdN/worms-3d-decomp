/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc27a_planner_set_gravity_8001aa48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc27a_gravity_80118288 = 0x80118288;
cc27a_mode_8001a758 = 0x8001a758;
cc27a_motion_8041e780 = 0x8041e780;
cc27a_name_8036af74 = 0x8036af74;
cc27a_origin_8001a770 = 0x8001a770;
cc27a_origin_8041e844 = 0x8041e844;
cc27a_property_800fc270 = 0x800fc270;
cc27a_set_80118230 = 0x80118230;
SECTIONS {
  .text.cc27a_planner_set_gravity_8001aa48 0x8001aa48 : { *(.text.cc27a_planner_set_gravity_8001aa48) }
  .rodata 0x8036afb8 : { *(.rodata) }
  .sdata 0x804b1770 (NOLOAD) : {
    . = 0x0; cc27a_scale_804b1770 = .;
    . = 0x4; cc27a_time_804b1774 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
