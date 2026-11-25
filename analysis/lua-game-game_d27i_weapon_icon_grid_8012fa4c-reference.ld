/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27i_weapon_icon_grid_8012fa4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
bot_80171ff8 = 0x80171ff8;
cast_80343808 = 0x80343808;
find_8015ae3c = 0x8015ae3c;
name_8039dd20 = 0x8039dd20;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
top_80171fa0 = 0x80171fa0;
SECTIONS {
  .text.d27i_weapon_icon_grid_8012fa4c 0x8012fa4c : { *(.text.d27i_weapon_icon_grid_8012fa4c) }
  .rodata 0x8039dd30 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
