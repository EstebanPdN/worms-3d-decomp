/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25d_worm_slide_start_8014e550)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
class_80361860 = 0x80361860;
class_803618f0 = 0x803618f0;
file_803a0e2c = 0x803a0e2c;
names_8014e4c8 = 0x8014e4c8;
random_801610a0 = 0x801610a0;
sqrt_802e82c0 = 0x802e82c0;
trace_80022e20 = 0x80022e20;
SECTIONS {
  .text.d25d_worm_slide_start_8014e550 0x8014e550 : { *(.text.d25d_worm_slide_start_8014e550) }
  .rodata 0x803a1728 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
