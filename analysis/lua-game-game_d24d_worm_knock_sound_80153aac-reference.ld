/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_worm_knock_sound_80153aac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_knock1_803a1ba4 = 0x803a1ba4;
d24d_knock2_803a1bb0 = 0x803a1bb0;
d24d_knock3_803a1bbc = 0x803a1bbc;
d24d_knock4_803a1bc8 = 0x803a1bc8;
d24d_random_80161080 = 0x80161080;
d24d_sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d24d_worm_knock_sound_80153aac 0x80153aac : { *(.text.d24d_worm_knock_sound_80153aac) }
  .rodata 0x803a1bd4 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; d24d_game_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
