/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_card_guide_step_802aba68)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
OSPanic = 0x802fb82c;
w3d_auto_802abedc = 0x802abedc;
w3d_auto_802abf58 = 0x802abf58;
w3d_card_status_802abfdc = 0x802abfdc;
w3d_cc17d_desc_setup_802abc28 = 0x802abc28;
w3d_check_card_802abd94 = 0x802abd94;
w3d_s4_memguide_probe_step = 0x802abcdc;
SECTIONS {
  .text.d24l_card_guide_step_802aba68 0x802aba68 : { *(.text.d24l_card_guide_step_802aba68) }
  .rodata 0x803d6c64 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
