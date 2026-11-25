/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32i_contour_walk_outline_8010bb1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
can_step_8010b594 = 0x8010b594;
case_bit_80399f68 = 0x80399f68;
case_turn_80399e88 = 0x80399e88;
cell_case_8010b560 = 0x8010b560;
emit_segment_8010aeb0 = 0x8010aeb0;
marks_8044c9ec = 0x8044c9ec;
memset_802eefe0 = 0x802eefe0;
next_start_8010b75c = 0x8010b75c;
segments_803fd5c0 = 0x803fd5c0;
step_x_80399ec8 = 0x80399ec8;
step_y_80399ed8 = 0x80399ed8;
SECTIONS {
  .text.d32i_contour_walk_outline_8010bb1c 0x8010bb1c : { *(.text.d32i_contour_walk_outline_8010bb1c) }
  .sdata 0x804af2b0 (NOLOAD) : {
    . = 0x0; scan_row_804af2b0 = .;
    . = 0x4; scan_column_804af2b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
