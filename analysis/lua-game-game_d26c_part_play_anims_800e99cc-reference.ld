/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_part_play_anims_800e99cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
check_8018179c = 0x8018179c;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
empty_text_8038b1f8 = 0x8038b1f8;
play_80181640 = 0x80181640;
strcmp = 0x802ef234;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d26c_part_play_anims_800e99cc 0x800e99cc : { *(.text.d26c_part_play_anims_800e99cc) }
  .rodata 0x8038b294 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
