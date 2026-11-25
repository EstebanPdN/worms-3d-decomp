/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc33a_hud_team_ranking_800661c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc33a_object_80164fc8 = 0x80164fc8;
cc33a_player_800fc6dc = 0x800fc6dc;
cc33a_set_80064190 = 0x80064190;
cc33a_team_800fc7f8 = 0x800fc7f8;
SECTIONS {
  .text.cc33a_hud_team_ranking_800661c4 0x800661c4 : { *(.text.cc33a_hud_team_ranking_800661c4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
