/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(handle_event__13D18fListPanelP9D18fEvent)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d18f_base_event_8015fb34 = 0x8015fb34;
d18f_control_event_802aff9c = 0x802aff9c;
d18f_control_ready_802b264c = 0x802b264c;
d18f_event_point_80069a50 = 0x80069a50;
d18f_list_count_802bc71c = 0x802bc71c;
d18f_list_select_802bc8b4 = 0x802bc8b4;
d18f_message_id_equals_8015f65c = 0x8015f65c;
d18f_panel_close_802b66c4 = 0x802b66c4;
d18f_panel_confirm_802b98dc = 0x802b98dc;
d18f_panel_finish_802b88b0 = 0x802b88b0;
d18f_panel_hit_802b8260 = 0x802b8260;
d18f_panel_hit_frame_802b9cf4 = 0x802b9cf4;
d18f_panel_hit_item_802b9bac = 0x802b9bac;
d18f_panel_open_802b6248 = 0x802b6248;
d18f_panel_reset_802ba0cc = 0x802ba0cc;
d18f_panel_show_802b83ac = 0x802b83ac;
SECTIONS {
  .text.handle_event__13D18fListPanelP9D18fEvent 0x802b5a9c : { *(.text.handle_event__13D18fListPanelP9D18fEvent) }
  .rodata 0x803d7f40 : { *(.rodata) }
  .sdata 0x804abb48 (NOLOAD) : {
    . = 0x0; d18f_input_locked_804abb48 = .;
    . = 0x54d0; d18f_id_point_804b1018 = .;
    . = 0x54d8; d18f_id_up_804b1020 = .;
    . = 0x54e0; d18f_id_down_804b1028 = .;
    . = 0x54e8; d18f_id_accept_804b1030 = .;
    . = 0x54f0; d18f_id_back_804b1038 = .;
    . = 0x54f8; d18f_id_left_804b1040 = .;
    . = 0x5500; d18f_id_right_804b1048 = .;
    . = 0x5508; d18f_id_drag_804b1050 = .;
    . = 0x5510; d18f_id_reset0_804b1058 = .;
    . = 0x5518; d18f_id_reset1_804b1060 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
