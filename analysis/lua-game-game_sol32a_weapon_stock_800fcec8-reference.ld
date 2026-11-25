/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol32a_weapon_stock_800fcec8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allianceStock_800fcd84 = 0x800fcd84;
delay_8025c3a8 = 0x8025c3a8;
enabled_800fd014 = 0x800fd014;
readIndex_800fc1f0 = 0x800fc1f0;
readProperty_800fc330 = 0x800fc330;
stock_8025cbe0 = 0x8025cbe0;
teamStock_800fcc68 = 0x800fcc68;
team_800fc7f8 = 0x800fc7f8;
wormStock_800fca30 = 0x800fca30;
worm_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.sol32a_weapon_stock_800fcec8 0x800fcec8 : { *(.text.sol32a_weapon_stock_800fcec8) }
  .rodata 0x803980e4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
