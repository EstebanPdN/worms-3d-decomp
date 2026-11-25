/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol31a_reset_motion_800d2f64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lookup_80341584 = 0x80341584;
parameters_801797b4 = 0x801797b4;
test_800d4b90 = 0x800d4b90;
SECTIONS {
  .text.sol31a_reset_motion_800d2f64 0x800d2f64 : { *(.text.sol31a_reset_motion_800d2f64) }
  .rodata 0x80388cb8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
