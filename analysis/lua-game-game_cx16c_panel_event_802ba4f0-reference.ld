/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16c_panel_event_802ba4f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx16c_base_event_8015fb34 = 0x8015fb34;
cx16c_context_802b264c = 0x802b264c;
cx16c_context_event_802aff9c = 0x802aff9c;
cx16c_initialize_802ba5c4 = 0x802ba5c4;
cx16c_release_802ba680 = 0x802ba680;
SECTIONS {
  .text.w3d_cx16c_panel_event_802ba4f0 0x802ba4f0 : { *(.text.w3d_cx16c_panel_event_802ba4f0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
