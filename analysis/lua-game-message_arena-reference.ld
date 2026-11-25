/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_message_arena_close)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_aligned_release = 0x801fe2e0;
SECTIONS {
  .text.w3d_message_arena_close 0x801613b8 : { *(.text.w3d_message_arena_close) }
  .text.w3d_message_arena_checkpoint 0x80161440 : { *(.text.w3d_message_arena_checkpoint) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
