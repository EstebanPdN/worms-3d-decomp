/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_countdown_cues_8025dbd0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
msgid_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
table_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d26k_countdown_cues_8025dbd0 0x8025dbd0 : { *(.text.w3d_d26k_countdown_cues_8025dbd0) }
  .sdata 0x804b0918 (NOLOAD) : {
    . = 0x0; cache_804b0918 = .;
    . = 0x8; cache_804b0920 = .;
    . = 0x10; cache_804b0928 = .;
    . = 0x18; cache_804b0930 = .;
    . = 0xe3c; global_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
