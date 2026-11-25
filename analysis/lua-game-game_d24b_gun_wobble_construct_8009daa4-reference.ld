/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_gun_wobble_construct_8009daa4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_engine_context_80165254 = 0x80165254;
w3d_float_read_800fc270 = 0x800fc270;
w3d_identity_803426b4 = 0x803426b4;
w3d_identity_80342a74 = 0x80342a74;
w3d_identity_80342a78 = 0x80342a78;
w3d_random_80162bc8 = 0x80162bc8;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_803804b4 = 0x803804b4;
w3d_string_803804c8 = 0x803804c8;
w3d_string_803804dc = 0x803804dc;
w3d_string_803804ec = 0x803804ec;
SECTIONS {
  .text.w3d_d24b_gun_wobble_construct_8009daa4 0x8009daa4 : { *(.text.w3d_d24b_gun_wobble_construct_8009daa4) }
  .rodata 0x803804fc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
