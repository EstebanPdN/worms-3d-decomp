/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_shared_object_set_mode)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_list_insert_8020fd04 = 0x8020fd04;
w3d_list_remove_8020fd2c = 0x8020fd2c;
w3d_operator_new_801fe1d8 = 0x801fe1d8;
w3d_shared_list = 0x80368c08;
w3d_shared_object_apply_mode_802c663c = 0x802c663c;
w3d_shared_object_construct_802c6b10 = 0x802c6b10;
w3d_shared_object_destroy_802c6c74 = 0x802c6c74;
SECTIONS {
  .text.w3d_shared_object_set_mode 0x802c6924 : { *(.text.w3d_shared_object_set_mode) }
  .text.w3d_shared_object_mark_state5 0x802c6954 : { *(.text.w3d_shared_object_mark_state5) }
  .text.w3d_shared_list_get 0x802c69ec : { *(.text.w3d_shared_list_get) }
  .text.w3d_shared_list_unlink 0x802c69f8 : { *(.text.w3d_shared_list_unlink) }
  .text.w3d_shared_object_create 0x802c6a3c : { *(.text.w3d_shared_object_create) }
  .text.w3d_shared_object_release 0x802c6a9c : { *(.text.w3d_shared_object_release) }
  .text.w3d_shared_object_retain 0x802c6af8 : { *(.text.w3d_shared_object_retain) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
