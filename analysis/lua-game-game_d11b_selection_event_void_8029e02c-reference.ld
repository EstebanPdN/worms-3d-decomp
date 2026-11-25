/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d11b_selection_event_void_8029e02c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d11b_event_base_handler_8015fb34 = 0x8015fb34;
d11b_event_current_context_802b264c = 0x802b264c;
d11b_event_equals_8015f65c = 0x8015f65c;
d11b_event_forward_802aff9c = 0x802aff9c;
d11b_event_reset_8029ea40 = 0x8029ea40;
d11b_event_set_slider_80296410 = 0x80296410;
d11b_event_setup_8029e584 = 0x8029e584;
d11b_event_step_803d1cfc = 0x803d1cfc;
SECTIONS {
  .text.d11b_selection_event_void_8029e02c 0x8029e02c : { *(.text.d11b_selection_event_void_8029e02c) }
  .sdata 0x804abb48 (NOLOAD) : {
    . = 0x0; d11b_event_blocked_804abb48 = .;
    . = 0x5314; d11b_previous_event_804b0e5c = .;
    . = 0x531c; d11b_next_event_804b0e64 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
