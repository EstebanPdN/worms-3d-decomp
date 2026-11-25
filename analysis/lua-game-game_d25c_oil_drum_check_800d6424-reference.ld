/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25c_oil_drum_check_800d6424)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
ctx_80165254 = 0x80165254;
position_80066894 = 0x80066894;
radius_800668e4 = 0x800668e4;
report_80022e20 = 0x80022e20;
type_80361860 = 0x80361860;
type_803618f0 = 0x803618f0;
SECTIONS {
  .text.d25c_oil_drum_check_800d6424 0x800d6424 : { *(.text.d25c_oil_drum_check_800d6424) }
  .rodata 0x80388e78 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
