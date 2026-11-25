/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_gun_fire_round_800e1268)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
clip_800e2464 = 0x800e2464;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
note_800dca14 = 0x800dca14;
play_800e5d4c = 0x800e5d4c;
random_8015ff7c = 0x8015ff7c;
SECTIONS {
  .text.d26c_gun_fire_round_800e1268 0x800e1268 : { *(.text.d26c_gun_fire_round_800e1268) }
  .rodata 0x80389dc0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
