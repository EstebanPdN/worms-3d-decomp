/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26d_worm_apply_impulse_80148c14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
blasted_803a129c = 0x803a129c;
classA_80361860 = 0x80361860;
classC_803618f0 = 0x803618f0;
detach_8014df84 = 0x8014df84;
entity_803a0e2c = 0x803a0e2c;
grounded_801510c4 = 0x801510c4;
hit_803a12ac = 0x803a12ac;
immune_80153f38 = 0x80153f38;
launch_80150828 = 0x80150828;
slot_80022e20 = 0x80022e20;
SECTIONS {
  .text.d26d_worm_apply_impulse_80148c14 0x80148c14 : { *(.text.d26d_worm_apply_impulse_80148c14) }
  .rodata 0x803a12b8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
