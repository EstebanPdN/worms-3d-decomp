/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24a_turn_time_remaining_800155d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_identity_803426b4 = 0x803426b4;
w3d_object_int_80178c48 = 0x80178c48;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_8036a5b4 = 0x8036a5b4;
w3d_string_8036a5c8 = 0x8036a5c8;
SECTIONS {
  .text.w3d_d24a_turn_time_remaining_800155d0 0x800155d0 : { *(.text.w3d_d24a_turn_time_remaining_800155d0) }
  .rodata 0x8036a5d8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
