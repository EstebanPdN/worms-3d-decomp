/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d11a_update_channels_800fdfec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d11a_one_803981cc = 0x803981cc;
d11a_set_channels_800fdf5c = 0x800fdf5c;
d11a_zero_803981c8 = 0x803981c8;
SECTIONS {
  .text.d11a_update_channels_800fdfec 0x800fdfec : { *(.text.d11a_update_channels_800fdfec) }
  .rodata 0x803981c0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
