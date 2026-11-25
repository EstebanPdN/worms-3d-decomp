/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25l_clear_selection_802b66c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._14F1pRecordOwner = 0x802bcfb4;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_auto_802b0fec = 0x802b0fec;
w3d_s21_release_slots_802ba070 = 0x802ba070;
SECTIONS {
  .text.d25l_clear_selection_802b66c4 0x802b66c4 : { *(.text.d25l_clear_selection_802b66c4) }
  .sdata 0x804abb4c (NOLOAD) : {
    . = 0x0; d25l_current_804abb4c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
