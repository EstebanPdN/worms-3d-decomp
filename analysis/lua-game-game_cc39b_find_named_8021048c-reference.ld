/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc39b_find_named_8021048c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc39b_active_head_8020ff3c = 0x8020ff3c;
cc39b_compare_802ef234 = 0x802ef234;
cc39b_node_name_801ffea8 = 0x801ffea8;
cc39b_pending_head_8020ff34 = 0x8020ff34;
SECTIONS {
  .text.cc39b_find_named_8021048c 0x8021048c : { *(.text.cc39b_find_named_8021048c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
