/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11a_interpolate_800ecd60)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
one_8038b5c4 = 0x8038b5c4;
refresh_801797b4 = 0x801797b4;
touch_80341584 = 0x80341584;
zero_8038b5c0 = 0x8038b5c0;
SECTIONS {
  .text.w3d_cx11a_interpolate_800ecd60 0x800ecd60 : { *(.text.w3d_cx11a_interpolate_800ecd60) }
  .rodata 0x8038b5b0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
