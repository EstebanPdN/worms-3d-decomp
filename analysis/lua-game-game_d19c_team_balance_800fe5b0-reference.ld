/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19c_team_balance_800fe5b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d19c_continue_8002ae70 = 0x8002ae70;
d19c_player_count_80158f68 = 0x80158f68;
d19c_property_write_800fc3b0 = 0x800fc3b0;
d19c_retreat_time_key_8039820c = 0x8039820c;
d19c_team_member_count_80158e74 = 0x80158e74;
d19c_team_record_800fc7f8 = 0x800fc7f8;
d19c_team_set_share_80158ea4 = 0x80158ea4;
d19c_worm_record_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.d19c_team_balance_800fe5b0 0x800fe5b0 : { *(.text.d19c_team_balance_800fe5b0) }
  .rodata 0x80398218 : { *(.rodata) }
  .sdata 0x804ab400 (NOLOAD) : {
    . = 0x0; d19c_teams_804ab400 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
