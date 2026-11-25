/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc42a_clear_group_80177d1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc42a_clear_80179770 = 0x80179770;
cc42a_emptyText_803a6d34 = 0x803a6d34;
cc42a_identity_80341584 = 0x80341584;
cc42a_identity_80343744 = 0x80343744;
cc42a_set_text_801790bc = 0x801790bc;
SECTIONS {
  .text.cc42a_clear_group_80177d1c 0x80177d1c : { *(.text.cc42a_clear_group_80177d1c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
