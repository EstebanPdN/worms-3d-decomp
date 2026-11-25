/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24a_gravity_water_start_800670e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_constant_8037a0c0 = 0x8037a0c0;
w3d_created_message_init_800c1620 = 0x800c1620;
w3d_engine_context_80165254 = 0x80165254;
w3d_identity_80342a74 = 0x80342a74;
w3d_message_post_8016239c = 0x8016239c;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_8037a094 = 0x8037a094;
w3d_string_8037a09c = 0x8037a09c;
w3d_string_8037a0b4 = 0x8037a0b4;
SECTIONS {
  .text.w3d_d24a_gravity_water_start_800670e0 0x800670e0 : { *(.text.w3d_d24a_gravity_water_start_800670e0) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; w3d_message_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
