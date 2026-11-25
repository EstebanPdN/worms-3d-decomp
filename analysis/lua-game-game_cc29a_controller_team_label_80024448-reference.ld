/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc29a_controller_team_label_80024448)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc29a_enable_800243a8 = 0x800243a8;
cc29a_label_8034357c = 0x8034357c;
cc29a_player_800fc6dc = 0x800fc6dc;
cc29a_refresh_800248f8 = 0x800248f8;
cc29a_set_80173df0 = 0x80173df0;
cc29a_team_800fd3e4 = 0x800fd3e4;
SECTIONS {
  .text.cc29a_controller_team_label_80024448 0x80024448 : { *(.text.cc29a_controller_team_label_80024448) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
