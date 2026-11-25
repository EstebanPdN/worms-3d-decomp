/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_handle_member_set_slot_word)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_handle_set_slot_word = 0x8003fbb8;
SECTIONS {
  .text.w3d_actor_handle_member_set_slot_word 0x801262e4 : { *(.text.w3d_actor_handle_member_set_slot_word) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
