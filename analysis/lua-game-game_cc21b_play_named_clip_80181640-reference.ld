/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc21b_play_named_clip_80181640)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc21b_find_clip_80181598 = 0x80181598;
cc21b_play_clip_801816d0 = 0x801816d0;
SECTIONS {
  .text.w3d_cc21b_play_named_clip_80181640 0x80181640 : { *(.text.w3d_cc21b_play_named_clip_80181640) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
