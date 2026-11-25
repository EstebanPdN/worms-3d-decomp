/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc43b_update_controls_80260144)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc43b_zero_803cab98 = 0x803cab98;
SECTIONS {
  .text.cc43b_update_controls_80260144 0x80260144 : { *(.text.cc43b_update_controls_80260144) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
