/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc38a_group_clear_800f6afc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc38a_destroy_800f6ca0 = 0x800f6ca0;
cc38a_move_802eee50 = 0x802eee50;
SECTIONS {
  .text.cc38a_group_clear_800f6afc 0x800f6afc : { *(.text.cc38a_group_clear_800f6afc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
