/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27j_play_sound_8019a868)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801907a8 = 0x801907a8;
manager_803439d8 = 0x803439d8;
prepare_801983cc = 0x801983cc;
release_801907d0 = 0x801907d0;
status_80198160 = 0x80198160;
SECTIONS {
  .text.d27j_play_sound_8019a868 0x8019a868 : { *(.text.d27j_play_sound_8019a868) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
