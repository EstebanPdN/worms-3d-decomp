/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28l_movie_mix_audio_802e1b8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802e220c = 0x802e220c;
memcpy = 0x802eee50;
volume_804040ec = 0x804040ec;
SECTIONS {
  .text.d28l_movie_mix_audio_802e1b8c 0x802e1b8c : { *(.text.d28l_movie_mix_audio_802e1b8c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
