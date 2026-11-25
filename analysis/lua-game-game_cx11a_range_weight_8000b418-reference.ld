/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11a_range_weight_8000b418)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
one_80369c54 = 0x80369c54;
root_802e82c0 = 0x802e82c0;
zero_80369c50 = 0x80369c50;
SECTIONS {
  .text.w3d_cx11a_range_weight_8000b418 0x8000b418 : { *(.text.w3d_cx11a_range_weight_8000b418) }
  .sdata 0x804aa750 (NOLOAD) : {
    . = 0x0; actors_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
