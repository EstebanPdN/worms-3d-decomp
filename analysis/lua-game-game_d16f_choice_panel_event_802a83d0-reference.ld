/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(handle_event__15D16fChoicePanelP9D16fEvent)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d16f_arena_alloc_801613f0 = 0x801613f0;
d16f_base_event_8015fb34 = 0x8015fb34;
d16f_cached_message_id_8015f5a0 = 0x8015f5a0;
d16f_control_event_802aff9c = 0x802aff9c;
d16f_control_ready_802b264c = 0x802b264c;
d16f_event_point_80069a50 = 0x80069a50;
d16f_message_id_equals_8015f65c = 0x8015f65c;
d16f_message_post_8016239c = 0x8016239c;
d16f_message_string_init_8010a8e0 = 0x8010a8e0;
d16f_panel_cancel_802aaa8c = 0x802aaa8c;
d16f_panel_close_802a9f54 = 0x802a9f54;
d16f_panel_open_802a90b8 = 0x802a90b8;
d16f_panel_pick_802ab5c0 = 0x802ab5c0;
d16f_panel_select_802aa8a4 = 0x802aa8a4;
SECTIONS {
  .text.handle_event__15D16fChoicePanelP9D16fEvent 0x802a83d0 : { *(.text.handle_event__15D16fChoicePanelP9D16fEvent) }
  .sdata 0x804abb48 (NOLOAD) : {
    . = 0x0; d16f_input_locked_804abb48 = .;
    . = 0x53a4; d16f_id_choice0_804b0eec = .;
    . = 0x53ac; d16f_id_choice1_804b0ef4 = .;
    . = 0x53b4; d16f_id_cancel_804b0efc = .;
    . = 0x53c4; d16f_id_choice2_804b0f0c = .;
    . = 0x53cc; d16f_id_choice3_804b0f14 = .;
    . = 0x53d4; d16f_id_point_804b0f1c = .;
    . = 0x53dc; d16f_id_selected_804b0f24 = .;
    . = 0x5c0c; d16f_message_queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
