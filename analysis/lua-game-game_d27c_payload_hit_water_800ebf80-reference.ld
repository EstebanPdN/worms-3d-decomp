/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_payload_hit_water_800ebf80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
asin_802e7c30 = 0x802e7c30;
desc_801797b4 = 0x801797b4;
effect_800e5ca4 = 0x800e5ca4;
empty_80341584 = 0x80341584;
empty_80342a74 = 0x80342a74;
sqrt_802e82c0 = 0x802e82c0;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.d27c_payload_hit_water_800ebf80 0x800ebf80 : { *(.text.d27c_payload_hit_water_800ebf80) }
  .rodata 0x8038b500 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
