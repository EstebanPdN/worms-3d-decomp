/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc25a_planner_powerup_duration_8001b660)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc25a_cast_80342a78 = 0x80342a78;
cc25a_key_8036b024 = 0x8036b024;
cc25a_lookup_800fc1b0 = 0x800fc1b0;
cc25a_read_80178d1c = 0x80178d1c;
cc25a_sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.cc25a_planner_powerup_duration_8001b660 0x8001b660 : { *(.text.cc25a_planner_powerup_duration_8001b660) }
  .rodata 0x8036b040 : { *(.rodata) }
  .sdata 0x804b1770 (NOLOAD) : {
    . = 0x0; cc25a_scale_804b1770 = .;
    . = 0x4; cc25a_offset_804b1774 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
