/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25d_worm_slide_stop_80150018)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
arena_801613f0 = 0x801613f0;
constrain_8014b40c = 0x8014b40c;
limit_8014c978 = 0x8014c978;
motion_direction_80146f10 = 0x80146f10;
msg_init_800a82f0 = 0x800a82f0;
msgid_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
sqrt_802e82c0 = 0x802e82c0;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d25d_worm_slide_stop_80150018 0x80150018 : { *(.text.d25d_worm_slide_stop_80150018) }
  .rodata 0x803a17d4 : { *(.rodata) }
  .sdata 0x804afc60 (NOLOAD) : {
    . = 0x0; cache_804afc60 = .;
    . = 0x1af4; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
