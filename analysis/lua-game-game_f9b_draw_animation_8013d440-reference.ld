/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f9b_draw_animation_8013d440)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
aim_80181884 = 0x80181884;
airstrike_8039f948 = 0x8039f948;
amount_8013c844 = 0x8013c844;
axe_8039f95c = 0x8039f95c;
bat_8039f968 = 0x8039f968;
blend_8039fa1c = 0x8039fa1c;
clear_801817e0 = 0x801817e0;
cow_8039f974 = 0x8039f974;
dynamite_8039f980 = 0x8039f980;
firepunch_8039f424 = 0x8039f424;
held_8013d730 = 0x8013d730;
mine_8039f994 = 0x8039f994;
play_801359ec = 0x801359ec;
prod_8039f9a4 = 0x8039f9a4;
rate_8039fa14 = 0x8039fa14;
scales_8039f9b4 = 0x8039f9b4;
sheep_8039f9c4 = 0x8039f9c4;
shotgun_8039fa04 = 0x8039fa04;
teleport_8039f9d4 = 0x8039f9d4;
thrown_8039f9e8 = 0x8039f9e8;
uzi_8039f9f8 = 0x8039f9f8;
zero_8039fa18 = 0x8039fa18;
SECTIONS {
  .text.f9b_draw_animation_8013d440 0x8013d440 : { *(.text.f9b_draw_animation_8013d440) }
  .sdata 0x804ab100 (NOLOAD) : {
    . = 0x0; neutral_804ab100 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
