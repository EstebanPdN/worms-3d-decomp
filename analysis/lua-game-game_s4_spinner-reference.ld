/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_spinner_repeat_step)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178c48 = 0x80178c48;
w3d_auto_80178d1c = 0x80178d1c;
w3d_constructor_native_cast = 0x80342a78;
w3d_empty_803426b4 = 0x803426b4;
w3d_float_store_80178d28 = 0x80178d28;
w3d_int_store_80178c54 = 0x80178c54;
w3d_selection_activate_802b0990 = 0x802b0990;
w3d_selection_name_802b1258 = 0x802b1258;
w3d_spinner_base_reset_802b0fec = 0x802b0fec;
w3d_spinner_base_step_802b0668 = 0x802b0668;
w3d_spinner_refresh_8028c290 = 0x8028c290;
w3d_spinner_update_controls_8028c64c = 0x8028c64c;
w3d_spinner_visibility_8028c160 = 0x8028c160;
w3d_text_destroy_8025e0c4 = 0x8025e0c4;
SECTIONS {
  .text.w3d_s4_spinner_repeat_step 0x8028b414 : { *(.text.w3d_s4_spinner_repeat_step) }
  .text.w3d_s4_spinner_reset 0x8028b750 : { *(.text.w3d_s4_spinner_reset) }
  .text.w3d_s4_spinner_set_active 0x8028b990 : { *(.text.w3d_s4_spinner_set_active) }
  .text.w3d_s4_spinner_increment 0x8028c508 : { *(.text.w3d_s4_spinner_increment) }
  .text.w3d_s4_spinner_decrement 0x8028c5b4 : { *(.text.w3d_s4_spinner_decrement) }
  .text.w3d_s4_spinner_set_editing 0x8028c6b0 : { *(.text.w3d_s4_spinner_set_editing) }
  .text.w3d_s4_spinner_value_changed 0x8028c71c : { *(.text.w3d_s4_spinner_value_changed) }
  .text.w3d_s4_spinner_read_value 0x8028c768 : { *(.text.w3d_s4_spinner_read_value) }
  .text.w3d_s4_spinner_write_value 0x8028c7fc : { *(.text.w3d_s4_spinner_write_value) }
  .text.w3d_s4_spinner_clear_texts 0x8028c888 : { *(.text.w3d_s4_spinner_clear_texts) }
  .sdata 0x804aac54 (NOLOAD) : {
    . = 0x0; w3d_input_804aac54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
