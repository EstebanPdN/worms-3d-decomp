/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32h_hud_clock_layout_800a30bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
castM_8034380c = 0x8034380c;
flag_80178d1c = 0x80178d1c;
number_80178df0 = 0x80178df0;
positions_80189518 = 0x80189518;
value_80178ec4 = 0x80178ec4;
SECTIONS {
  .text.d32h_hud_clock_layout_800a30bc 0x800a30bc : { *(.text.d32h_hud_clock_layout_800a30bc) }
  .rodata 0x80380cb4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
