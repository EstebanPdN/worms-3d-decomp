/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(handle_event__11D17fSpinnerP9D17fEvent)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d17f_base_event_8015fb34 = 0x8015fb34;
d17f_control_edge_802b22b0 = 0x802b22b0;
d17f_control_event_802aff9c = 0x802aff9c;
d17f_control_ready_802b264c = 0x802b264c;
d17f_event_point_80069a50 = 0x80069a50;
d17f_message_id_equals_8015f65c = 0x8015f65c;
d17f_play_sound_802b1258 = 0x802b1258;
d17f_spinner_decrement_8028c5b4 = 0x8028c5b4;
d17f_spinner_increment_8028c508 = 0x8028c508;
d17f_spinner_open_8028b4bc = 0x8028b4bc;
d17f_spinner_reset_8028b750 = 0x8028b750;
d17f_spinner_set_editing_8028c6b0 = 0x8028c6b0;
SECTIONS {
  .text.handle_event__11D17fSpinnerP9D17fEvent 0x8028b008 : { *(.text.handle_event__11D17fSpinnerP9D17fEvent) }
  .sdata 0x804abb48 (NOLOAD) : {
    . = 0x0; d17f_input_locked_804abb48 = .;
    . = 0x510c; d17f_id_edit_804b0c54 = .;
    . = 0x5114; d17f_id_leave_d_804b0c5c = .;
    . = 0x511c; d17f_id_point_up_804b0c64 = .;
    . = 0x5124; d17f_id_leave_b_804b0c6c = .;
    . = 0x512c; d17f_id_point_down_804b0c74 = .;
    . = 0x5134; d17f_id_leave_a_804b0c7c = .;
    . = 0x513c; d17f_id_up_804b0c84 = .;
    . = 0x5144; d17f_id_down_804b0c8c = .;
    . = 0x5154; d17f_id_leave_c_804b0c9c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
