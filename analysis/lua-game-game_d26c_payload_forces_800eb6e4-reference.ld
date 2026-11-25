/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_payload_forces_800eb6e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cos_802e86d4 = 0x802e86d4;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
empty_80342a74 = 0x80342a74;
name_80342a78 = 0x80342a78;
sin_802e88ac = 0x802e88ac;
value_80178d1c = 0x80178d1c;
value_80178df0 = 0x80178df0;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d26c_payload_forces_800eb6e4 0x800eb6e4 : { *(.text.d26c_payload_forces_800eb6e4) }
  .rodata 0x8038b4e0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
