/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc43a_message_end_80160828)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc43a_allocate_801613f0 = 0x801613f0;
cc43a_dispatch_8015fc84 = 0x8015fc84;
cc43a_messageIds_803fe234 = 0x803fe234;
cc43a_messageVtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.cc43a_message_end_80160828 0x80160828 : { *(.text.cc43a_message_end_80160828) }
  .rodata 0x803a4664 : { *(.rodata) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; cc43a_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
