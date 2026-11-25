/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19c_nearest_sphere_801263fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d19c_registry_entry_8003f240 = 0x8003f240;
d19c_sphere_query_begin_8003fc70 = 0x8003fc70;
d19c_sphere_query_end_8003ffac = 0x8003ffac;
SECTIONS {
  .text.d19c_nearest_sphere_801263fc 0x801263fc : { *(.text.d19c_nearest_sphere_801263fc) }
  .rodata 0x8039bbb0 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; d19c_query_hit_804aa95e = .;
    . = 0x6e32; d19c_query_distance_804b1790 = .;
    . = 0x6e46; d19c_query_fraction_804b17a4 = .;
    . = 0x6e56; d19c_query_next_804b17b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
