/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12b_file_extent_query_8021d830)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
close_8020810c = 0x8020810c;
construct_80207fec = 0x80207fec;
destroy_8020803c = 0x8020803c;
extent_802081c8 = 0x802081c8;
open_802080a0 = 0x802080a0;
SECTIONS {
  .text.w3d_cx12b_file_extent_query_8021d830 0x8021d830 : { *(.text.w3d_cx12b_file_extent_query_8021d830) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
