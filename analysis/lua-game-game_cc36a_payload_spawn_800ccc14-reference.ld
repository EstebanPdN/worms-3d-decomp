/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc36a_payload_spawn_800ccc14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__26cc36a_Translation_80343740 = 0x80343740;
cc36a_lookup_80181e3c = 0x80181e3c;
cc36a_mesh_80343584 = 0x80343584;
cc36a_name_80387df8 = 0x80387df8;
cc36a_origin_8045e788 = 0x8045e788;
cc36a_transform_80181e18 = 0x80181e18;
SECTIONS {
  .text.cc36a_payload_spawn_800ccc14 0x800ccc14 : { *(.text.cc36a_payload_spawn_800ccc14) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
