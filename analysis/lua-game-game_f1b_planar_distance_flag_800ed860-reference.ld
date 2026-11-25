/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f1b_planar_distance_flag_800ed860)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
point_80448c90 = 0x80448c90;
SECTIONS {
  .text.f1b_planar_distance_flag_800ed860 0x800ed860 : { *(.text.f1b_planar_distance_flag_800ed860) }
  .rodata 0x8038b61c : { *(.rodata) }
  .sdata 0x804aaef8 (NOLOAD) : {
    . = 0x0; enabled_804aaef8 = .;
    . = 0x4; flag_804aaefc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
