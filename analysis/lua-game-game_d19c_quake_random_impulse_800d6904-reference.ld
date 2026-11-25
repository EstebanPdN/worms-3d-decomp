/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19c_quake_random_impulse_800d6904)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d19c_random_unit_80162bc8 = 0x80162bc8;
d19c_settings_read_float_800fc270 = 0x800fc270;
SECTIONS {
  .text.d19c_quake_random_impulse_800d6904 0x800d6904 : { *(.text.d19c_quake_random_impulse_800d6904) }
  .rodata 0x80388f80 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
