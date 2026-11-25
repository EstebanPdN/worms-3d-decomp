/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc39a_worm_proximity_80107f54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc39a_active_80399b20 = 0x80399b20;
cc39a_height_80399b34 = 0x80399b34;
cc39a_property_800fc1f0 = 0x800fc1f0;
cc39a_query_800b0824 = 0x800b0824;
cc39a_runtimeVector_8045e788 = 0x8045e788;
cc39a_target_800fc6dc = 0x800fc6dc;
cc39a_zero_80399b30 = 0x80399b30;
SECTIONS {
  .text.cc39a_worm_proximity_80107f54 0x80107f54 : { *(.text.cc39a_worm_proximity_80107f54) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; cc39a_distance_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
