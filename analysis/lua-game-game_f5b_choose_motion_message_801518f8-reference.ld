/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f5b_choose_motion_message_801518f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_801613f0 = 0x801613f0;
construct_80131b50 = 0x80131b50;
distance_803a193c = 0x803a193c;
height_803a1940 = 0x803a1940;
name_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
reset_8015286c = 0x8015286c;
value_8040db38 = 0x8040db38;
zero_803a1938 = 0x803a1938;
SECTIONS {
  .text.f5b_choose_motion_message_801518f8 0x801518f8 : { *(.text.f5b_choose_motion_message_801518f8) }
  .sdata 0x804afc90 (NOLOAD) : {
    . = 0x0; name_804afc90 = .;
    . = 0x1ac4; queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
