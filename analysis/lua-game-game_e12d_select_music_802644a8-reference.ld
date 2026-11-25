/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(e12d_select_music_802644a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_compare_text_802ef074 = 0x802ef074;
w3d_track_credits_803cb2b0 = 0x803cb2b0;
w3d_track_instrumental_803cb288 = 0x803cb288;
w3d_track_intro_803cb2a0 = 0x803cb2a0;
w3d_track_normal_803caf0c = 0x803caf0c;
w3d_track_vocal_803cb298 = 0x803cb298;
w3d_track_wormsong_803cb2b8 = 0x803cb2b8;
SECTIONS {
  .text.e12d_select_music_802644a8 0x802644a8 : { *(.text.e12d_select_music_802644a8) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_services_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
