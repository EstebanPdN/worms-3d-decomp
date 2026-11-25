/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc33a_hud_remaining_totals_800663a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc33a_object_80164fc8 = 0x80164fc8;
cc33a_player_800fc6dc = 0x800fc6dc;
cc33a_set_8006456c = 0x8006456c;
cc33a_team_800fc7f8 = 0x800fc7f8;
SECTIONS {
  .text.cc33a_hud_remaining_totals_800663a8 0x800663a8 : { *(.text.cc33a_hud_remaining_totals_800663a8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
