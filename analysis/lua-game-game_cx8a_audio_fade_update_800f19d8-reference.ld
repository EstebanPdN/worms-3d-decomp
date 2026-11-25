/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx8a_audio_fade_update_800f19d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
expire_8015fd1c = 0x8015fd1c;
fade_prepare_800f1a70 = 0x800f1a70;
fade_step_800f1b58 = 0x800f1b58;
stop_volume_8038c3e4 = 0x8038c3e4;
SECTIONS {
  .text.w3d_cx8a_audio_fade_update_800f19d8 0x800f19d8 : { *(.text.w3d_cx8a_audio_fade_update_800f19d8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
