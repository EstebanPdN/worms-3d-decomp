/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25a_commentary_interrupt_80044638)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_commentary_advance_800438d4 = 0x800438d4;
w3d_commentary_play_80043134 = 0x80043134;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_header_80341884 = 0x80341884;
w3d_string_init_8020c5c0 = 0x8020c5c0;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d25a_commentary_interrupt_80044638 0x80044638 : { *(.text.w3d_d25a_commentary_interrupt_80044638) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
