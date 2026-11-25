/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25c_orbit_update_800d6e14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cosf_802e86d4 = 0x802e86d4;
sinf_802e88ac = 0x802e88ac;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.d25c_orbit_update_800d6e14 0x800d6e14 : { *(.text.d25c_orbit_update_800d6e14) }
  .rodata 0x80389098 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
