/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_handle_is_one_800a14f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s8_visibility_800a3c24 = 0x800a3c24;
w3d_auto_80178d1c = 0x80178d1c;
SECTIONS {
  .text.s19_handle_is_one_800a14f4 0x800a14f4 : { *(.text.s19_handle_is_one_800a14f4) }
  .text.s19_visibility_hide_800a3bb4 0x800a3bb4 : { *(.text.s19_visibility_hide_800a3bb4) }
  .text.s19_visibility_show_800a3bec 0x800a3bec : { *(.text.s19_visibility_show_800a3bec) }
  .text.s19_reset_800b12c8 0x800b12c8 : { *(.text.s19_reset_800b12c8) }
  .text.s19_mode_is_two_800cfc98 0x800cfc98 : { *(.text.s19_mode_is_two_800cfc98) }
  .text.s19_vec3_copy_800d0f74 0x800d0f74 : { *(.text.s19_vec3_copy_800d0f74) }
  .text.s19_set_vec_pair_800dc3dc 0x800dc3dc : { *(.text.s19_set_vec_pair_800dc3dc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
