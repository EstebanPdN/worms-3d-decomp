/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12b_endpoint_name_reserve_802cc4f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
compare_802ef234 = 0x802ef234;
copy_802efbfc = 0x802efbfc;
empty_803d9460 = 0x803d9460;
names_804a9d38 = 0x804a9d38;
SECTIONS {
  .text.w3d_cx12b_endpoint_name_reserve_802cc4f0 0x802cc4f0 : { *(.text.w3d_cx12b_endpoint_name_reserve_802cc4f0) }
  .sdata 0x804abce4 (NOLOAD) : {
    . = 0x0; enabled_804abce4 = .;
    . = 0x4; dirty_804abce8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
