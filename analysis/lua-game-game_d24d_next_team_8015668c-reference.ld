/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_next_team_8015668c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._11d24d_Handle = 0x80178474;
d24d_game_init_803a2aa4 = 0x803a2aa4;
d24d_setting_lookup_800fc1b0 = 0x800fc1b0;
d24d_settings_get_80179598 = 0x80179598;
d24d_settings_view_80341584 = 0x80341584;
d24d_team_record_800fc7f8 = 0x800fc7f8;
SECTIONS {
  .text.d24d_next_team_8015668c 0x8015668c : { *(.text.d24d_next_team_8015668c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
