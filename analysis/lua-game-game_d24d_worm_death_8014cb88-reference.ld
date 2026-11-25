/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_worm_death_8014cb88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_arena_alloc_801613f0 = 0x801613f0;
d24d_effect_800e5ca4 = 0x800e5ca4;
d24d_effect_water_803a15b8 = 0x803a15b8;
d24d_effect_worm_803a15d0 = 0x803a15d0;
d24d_explosion_message_800666b4 = 0x800666b4;
d24d_message_post_8016239c = 0x8016239c;
d24d_post_death_8014fee8 = 0x8014fee8;
d24d_setting_803a152c = 0x803a152c;
d24d_setting_803a154c = 0x803a154c;
d24d_setting_803a1568 = 0x803a1568;
d24d_setting_803a1584 = 0x803a1584;
d24d_setting_803a15a0 = 0x803a15a0;
d24d_setting_read_800fc270 = 0x800fc270;
d24d_ten_803a15e4 = 0x803a15e4;
d24d_water_level_80178df0 = 0x80178df0;
SECTIONS {
  .text.d24d_worm_death_8014cb88 0x8014cb88 : { *(.text.d24d_worm_death_8014cb88) }
  .rodata 0x803a15e8 : { *(.rodata) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; d24d_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
