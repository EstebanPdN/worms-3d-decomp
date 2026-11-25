/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28d_worm_play_weapon_idle_80138dac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
assign_8020bd38 = 0x8020bd38;
control_801817e0 = 0x801817e0;
current_80139158 = 0x80139158;
draw_8013d730 = 0x8013d730;
effect_8013d8f8 = 0x8013d8f8;
empty_8039f59c = 0x8039f59c;
find_80181598 = 0x80181598;
length_80181de4 = 0x80181de4;
play_801359ec = 0x801359ec;
play_index_80135a70 = 0x80135a70;
read_800fc330 = 0x800fc330;
strcmp_802ef234 = 0x802ef234;
strstr_802efd14 = 0x802efd14;
table_803eb63c = 0x803eb63c;
SECTIONS {
  .text.d28d_worm_play_weapon_idle_80138dac 0x80138dac : { *(.text.d28d_worm_play_weapon_idle_80138dac) }
  .rodata 0x8039f640 : { *(.rodata) }
  .sdata 0x804ab100 (NOLOAD) : {
    . = 0x0; idle_804ab100 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
