/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_damage_scale_8000af90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800fc1f0 = 0x800fc1f0;
SECTIONS {
  .text.s19_damage_scale_8000af90 0x8000af90 : { *(.text.s19_damage_scale_8000af90) }
  .rodata 0x80369bfc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
