/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16c_panel_event_8028cf58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx16c_base_event_8015fb34 = 0x8015fb34;
cx16c_context_802b264c = 0x802b264c;
cx16c_context_event_802aff9c = 0x802aff9c;
cx16c_initialize_8028d1e4 = 0x8028d1e4;
cx16c_release_8028d274 = 0x8028d274;
SECTIONS {
  .text.w3d_cx16c_panel_event_8028cf58 0x8028cf58 : { *(.text.w3d_cx16c_panel_event_8028cf58) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
