/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_r24a_copy_retain_800ccd04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
container_type_803a9980 = 0x803a9980;
damping_803898a0 = 0x803898a0;
lua_check_type_802dcf90 = 0x802dcf90;
lua_equal_802cdbd0 = 0x802cdbd0;
lua_get_metatable_802ce3d4 = 0x802ce3d4;
lua_set_top_802cd808 = 0x802cd808;
lua_to_userdata_802cde08 = 0x802cde08;
lua_type_error_802dcd3c = 0x802dcd3c;
stiffness_8038989c = 0x8038989c;
SECTIONS {
  .text.w3d_r24a_copy_retain_800ccd04 0x800ccd04 : { *(.text.w3d_r24a_copy_retain_800ccd04) }
  .text.w3d_r24a_damp_value_800dbd74 0x800dbd74 : { *(.text.w3d_r24a_damp_value_800dbd74) }
  .text.w3d_r24a_append_empty_entry_8016e908 0x8016e908 : { *(.text.w3d_r24a_append_empty_entry_8016e908) }
  .text.w3d_r24a_check_container_userdata_8019e68c 0x8019e68c : { *(.text.w3d_r24a_check_container_userdata_8019e68c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
