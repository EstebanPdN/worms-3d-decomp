/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25d_worm_aim_point_80152474)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_801613f0 = 0x801613f0;
link_8014dc04 = 0x8014dc04;
lookup_80164fc8 = 0x80164fc8;
msg_80131b50 = 0x80131b50;
msgid_8015f5a0 = 0x8015f5a0;
mvt_8040db38 = 0x8040db38;
post_8016239c = 0x8016239c;
reset_8015286c = 0x8015286c;
SECTIONS {
  .text.d25d_worm_aim_point_80152474 0x80152474 : { *(.text.d25d_worm_aim_point_80152474) }
  .rodata 0x803a1a4c : { *(.rodata) }
  .sdata 0x804afe04 (NOLOAD) : {
    . = 0x0; cache_804afe04 = .;
    . = 0x1950; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
