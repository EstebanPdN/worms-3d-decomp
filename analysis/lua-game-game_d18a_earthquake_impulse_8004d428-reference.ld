/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d18a_earthquake_impulse_8004d428)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d18a_random_80162bc8 = 0x80162bc8;
d18a_read_float_setting_800fc270 = 0x800fc270;
SECTIONS {
  .text.w3d_d18a_earthquake_impulse_8004d428 0x8004d428 : { *(.text.w3d_d18a_earthquake_impulse_8004d428) }
  .rodata 0x803774bc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
