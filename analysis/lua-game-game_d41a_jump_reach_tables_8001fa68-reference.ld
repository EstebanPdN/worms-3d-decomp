/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41a_jump_reach_tables_8001fa68)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s_forward_8036b9f4 = 0x8036b9f4;
s_gravity_8036b9ec = 0x8036b9ec;
sqrt_802e82c0 = 0x802e82c0;
w3d_auto_80178ec4 = 0x80178ec4;
w3d_empty_80342a74 = 0x80342a74;
w3d_empty_80342fa4 = 0x80342fa4;
w3d_heap_alloc_801fe220 = 0x801fe220;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_value_80178df0 = 0x80178df0;
SECTIONS {
  .text.w3d_d41a_jump_reach_tables_8001fa68 0x8001fa68 : { *(.text.w3d_d41a_jump_reach_tables_8001fa68) }
  .rodata 0x8036ba08 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
