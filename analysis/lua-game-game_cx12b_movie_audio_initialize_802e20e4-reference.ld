/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12b_movie_audio_initialize_802e20e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_802098fc = 0x802098fc;
cache_802fa988 = 0x802fa988;
callback_802e1f88 = 0x802e1f88;
clear_802eefe0 = 0x802eefe0;
install_80311210 = 0x80311210;
lock_802fdb6c = 0x802fdb6c;
message_803db370 = 0x803db370;
start_803112dc = 0x803112dc;
submit_80311254 = 0x80311254;
trace_802fb7ac = 0x802fb7ac;
unlock_802fdb94 = 0x802fdb94;
SECTIONS {
  .text.w3d_cx12b_movie_audio_initialize_802e20e4 0x802e20e4 : { *(.text.w3d_cx12b_movie_audio_initialize_802e20e4) }
  .sdata 0x804ab8b4 (NOLOAD) : {
    . = 0x0; heap_804ab8b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
