/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_advance_team_worm_80155ff0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_active_worm_803a27ac = 0x803a27ac;
d24d_display_803426b4 = 0x803426b4;
d24d_display_update_80178c54 = 0x80178c54;
d24d_setting_read_800fc1f0 = 0x800fc1f0;
d24d_team_update_801558dc = 0x801558dc;
d24d_worm_info_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.d24d_advance_team_worm_80155ff0 0x80155ff0 : { *(.text.d24d_advance_team_worm_80155ff0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
