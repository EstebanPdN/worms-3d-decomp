/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d23a_briefing_panel_start_8002fcd0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_identity_80341584 = 0x80341584;
w3d_identity_80342a74 = 0x80342a74;
w3d_identity_80342a78 = 0x80342a78;
w3d_identity_80343744 = 0x80343744;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_80372fc0 = 0x80372fc0;
w3d_string_80372fd4 = 0x80372fd4;
w3d_string_80372fec = 0x80372fec;
w3d_string_80373004 = 0x80373004;
w3d_string_8037301c = 0x8037301c;
w3d_string_80373034 = 0x80373034;
w3d_string_8037304c = 0x8037304c;
w3d_string_80373068 = 0x80373068;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.w3d_d23a_briefing_panel_start_8002fcd0 0x8002fcd0 : { *(.text.w3d_d23a_briefing_panel_start_8002fcd0) }
  .sdata 0x804acd4c (NOLOAD) : {
    . = 0x0; w3d_message_804acd4c = .;
    . = 0x8; w3d_message_804acd54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
