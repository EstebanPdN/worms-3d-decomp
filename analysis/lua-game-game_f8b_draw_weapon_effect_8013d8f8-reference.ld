/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f8b_draw_weapon_effect_8013d8f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
axe_8039fae4 = 0x8039fae4;
bat_8039faf0 = 0x8039faf0;
bazooka_8039fa90 = 0x8039fa90;
cow_8039fab0 = 0x8039fab0;
grenade_8039faa0 = 0x8039faa0;
item_8039fb50 = 0x8039fb50;
nuke_8039fb08 = 0x8039fb08;
pigeon_8039fafc = 0x8039fafc;
punch_8039fb20 = 0x8039fb20;
quake_8039fb14 = 0x8039fb14;
redbull_8039fb40 = 0x8039fb40;
sheep_8039fabc = 0x8039fabc;
shotgun_8039fac8 = 0x8039fac8;
uzi_8039fad8 = 0x8039fad8;
woman_8039fb30 = 0x8039fb30;
SECTIONS {
  .text.f8b_draw_weapon_effect_8013d8f8 0x8013d8f8 : { *(.text.f8b_draw_weapon_effect_8013d8f8) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
