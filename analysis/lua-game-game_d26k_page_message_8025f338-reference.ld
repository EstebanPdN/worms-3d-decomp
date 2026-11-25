/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_page_message_8025f338)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
activate_802b1258 = 0x802b1258;
base_8015fb34 = 0x8015fb34;
current_802b264c__4View = 0x802b264c;
forward_802aff9c__4ViewP7Message = 0x802aff9c;
hide_8025fa40 = 0x8025fa40;
payload_8010a8fc = 0x8010a8fc;
report_802b22b0__4View = 0x802b22b0;
same_8015f65c = 0x8015f65c;
show_8025f54c = 0x8025f54c;
strcmp_802ef234 = 0x802ef234;
SECTIONS {
  .text.w3d_d26k_page_message_8025f338 0x8025f338 : { *(.text.w3d_d26k_page_message_8025f338) }
  .sdata 0x804abb48 (NOLOAD) : {
    . = 0x0; global_804abb48 = .;
    . = 0x4e10; cache_804b0958 = .;
    . = 0x4e18; cache_804b0960 = .;
    . = 0x4e20; cache_804b0968 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
