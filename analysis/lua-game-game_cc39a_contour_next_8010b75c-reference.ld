/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc39a_contour_next_8010b75c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc39a_backtrack_8010b5e8 = 0x8010b5e8;
cc39a_cell_8010b560 = 0x8010b560;
cc39a_inside_8010b594 = 0x8010b594;
cc39a_marks_8044c9ec = 0x8044c9ec;
cc39a_start_80399ee8 = 0x80399ee8;
SECTIONS {
  .text.cc39a_contour_next_8010b75c 0x8010b75c : { *(.text.cc39a_contour_next_8010b75c) }
  .sdata 0x804af2b0 (NOLOAD) : {
    . = 0x0; cc39a_row_804af2b0 = .;
    . = 0x4; cc39a_column_804af2b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
