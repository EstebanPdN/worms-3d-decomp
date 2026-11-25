/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc38a_script_clear_80102474)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc38a_destroy_800ffb78 = 0x800ffb78;
cc38a_move_802eee50 = 0x802eee50;
SECTIONS {
  .text.cc38a_script_clear_80102474 0x80102474 : { *(.text.cc38a_script_clear_80102474) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
