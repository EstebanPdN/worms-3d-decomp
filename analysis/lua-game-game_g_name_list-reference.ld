/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_name_list_init_800c4598)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_handle_storage_release = 0x802134fc;
w3d_memcpy_802eee50 = 0x802eee50;
w3d_string_assign = 0x8020bd38;
SECTIONS {
  .text.w3d_name_list_init_800c4598 0x800c4598 : { *(.text.w3d_name_list_init_800c4598) }
  .text.w3d_name_list_destroy_800c45b8 0x800c45b8 : { *(.text.w3d_name_list_destroy_800c45b8) }
  .text.w3d_name_list_clear_800c4604 0x800c4604 : { *(.text.w3d_name_list_clear_800c4604) }
  .text.w3d_name_list_count_800c4660 0x800c4660 : { *(.text.w3d_name_list_count_800c4660) }
  .text.w3d_name_list_pop_back_800c4d38 0x800c4d38 : { *(.text.w3d_name_list_pop_back_800c4d38) }
  .text.w3d_name_list_back_800c4d9c 0x800c4d9c : { *(.text.w3d_name_list_back_800c4d9c) }
  .text.w3d_name_list_freeze_800c4de8 0x800c4de8 : { *(.text.w3d_name_list_freeze_800c4de8) }
  .text.w3d_name_list_trim_800c4e18 0x800c4e18 : { *(.text.w3d_name_list_trim_800c4e18) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
