/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc36a_selection_events_800b96e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc36a_append_800ba4c4 = 0x800ba4c4;
cc36a_apply_800b9c1c = 0x800b9c1c;
cc36a_base_event_8015fb34 = 0x8015fb34;
cc36a_clear_800b9a48 = 0x800b9a48;
cc36a_key_matches_8015f620 = 0x8015f620;
cc36a_payload_8010a8fc = 0x8010a8fc;
cc36a_refresh_800b9e58 = 0x800b9e58;
cc36a_reset_800b9b0c = 0x800b9b0c;
cc36a_selection_8004d978 = 0x8004d978;
cc36a_setup_800b983c = 0x800b983c;
cc36a_shutdown_800ba5f8 = 0x800ba5f8;
SECTIONS {
  .text.cc36a_selection_events_800b96e4 0x800b96e4 : { *(.text.cc36a_selection_events_800b96e4) }
  .sdata 0x804aad30 (NOLOAD) : {
    . = 0x0; cc36a_owner_804aad30 = .;
    . = 0x37e8; cc36a_cache_804ae518 = .;
    . = 0x37f0; cc36a_cache_804ae520 = .;
    . = 0x37f8; cc36a_cache_804ae528 = .;
    . = 0x3810; cc36a_cache_804ae540 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
