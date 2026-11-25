/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_trail_owner_vector_800cd0d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_80387e24 = 0x80387e24;
w3d_get_800d1c14 = 0x800d1c14;
w3d_getf_800d1128 = 0x800d1128;
w3d_owner_resolve_80164fc8 = 0x80164fc8;
w3d_owner_vector_800d1104 = 0x800d1104;
w3d_zero_vector_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_trail_owner_vector_800cd0d0 0x800cd0d0 : { *(.text.w3d_trail_owner_vector_800cd0d0) }
  .text.w3d_trail_owner_float_800cd13c 0x800cd13c : { *(.text.w3d_trail_owner_float_800cd13c) }
  .text.w3d_trail_owner_value_800cd7fc 0x800cd7fc : { *(.text.w3d_trail_owner_value_800cd7fc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
