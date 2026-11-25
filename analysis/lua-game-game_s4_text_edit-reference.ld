/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_text_edit_construct)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_constructor_native_cast = 0x80342a78;
w3d_cursor_update_802a2524 = 0x802a2524;
w3d_str_803d1ef0 = 0x803d1ef0;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_default = 0x803426b8;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
w3d_subscribe_80162024 = 0x80162024;
w3d_text_list_ctor_8029dd4c = 0x8029dd4c;
w3d_text_list_dtor_8029de6c = 0x8029de6c;
w3d_vtable_8041c348 = 0x8041c348;
w3d_vtable_8041c398 = 0x8041c398;
SECTIONS {
  .text.w3d_s4_text_edit_construct 0x802a1730 : { *(.text.w3d_s4_text_edit_construct) }
  .text.w3d_s4_text_edit_destroy 0x802a17a4 : { *(.text.w3d_s4_text_edit_destroy) }
  .text.w3d_s4_text_edit_initialize_cursor 0x802a1a80 : { *(.text.w3d_s4_text_edit_initialize_cursor) }
  .sdata 0x804b0e70 (NOLOAD) : {
    . = 0x0; w3d_message_804b0e70 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
