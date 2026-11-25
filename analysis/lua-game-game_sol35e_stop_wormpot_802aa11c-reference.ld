/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35e_stop_wormpot_802aa11c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35e_audio_outro_803d699c = 0x803d699c;
sol35e_check_control_8018179c = 0x8018179c;
sol35e_dispatch_labels_802ab24c = 0x802ab24c;
sol35e_machine_outro_803d698c = 0x803d698c;
sol35e_panel_outro_802b1f98 = 0x802b1f98;
sol35e_play_clip_80181640 = 0x80181640;
sol35e_release_owner_8015fd1c = 0x8015fd1c;
SECTIONS {
  .text.sol35e_stop_wormpot_802aa11c 0x802aa11c : { *(.text.sol35e_stop_wormpot_802aa11c) }
  .rodata 0x803d69ac : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; sol35e_outro_context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
