/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc27a_grid_refresh_radius_8001e49c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc27a_clock_80178df0 = 0x80178df0;
cc27a_refresh_8001cc90 = 0x8001cc90;
cc27a_sqrt_802e82c0 = 0x802e82c0;
cc27a_touch_80342a74 = 0x80342a74;
SECTIONS {
  .text.cc27a_grid_refresh_radius_8001e49c 0x8001e49c : { *(.text.cc27a_grid_refresh_radius_8001e49c) }
  .rodata 0x8036b848 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
