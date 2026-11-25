/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(handle_event__18D16fValueSelectionP9D16fEvent)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d16f_base_event_8015fb34 = 0x8015fb34;
d16f_control_edge_802b22b0 = 0x802b22b0;
d16f_control_event_802aff9c = 0x802aff9c;
d16f_control_ready_802b264c = 0x802b264c;
d16f_message_id_equals_8015f65c = 0x8015f65c;
d16f_selection_announce_802b1258 = 0x802b1258;
d16f_selection_highlight_80286b40 = 0x80286b40;
d16f_selection_navigate_80286da4 = 0x80286da4;
d16f_selection_open_80285b28 = 0x80285b28;
d16f_selection_reset_80285c9c = 0x80285c9c;
d16f_update_kind0_80178c54 = 0x80178c54;
d16f_update_kind1_80178d28 = 0x80178d28;
d16f_view_kind0_803426b4 = 0x803426b4;
d16f_view_kind1_80342a78 = 0x80342a78;
SECTIONS {
  .text.handle_event__18D16fValueSelectionP9D16fEvent 0x8028581c : { *(.text.handle_event__18D16fValueSelectionP9D16fEvent) }
  .sdata 0x804abb48 (NOLOAD) : {
    . = 0x0; d16f_input_locked_804abb48 = .;
    . = 0x5054; d16f_id_next_a_804b0b9c = .;
    . = 0x505c; d16f_id_previous_a_804b0ba4 = .;
    . = 0x5064; d16f_id_next_b_804b0bac = .;
    . = 0x506c; d16f_id_previous_b_804b0bb4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
