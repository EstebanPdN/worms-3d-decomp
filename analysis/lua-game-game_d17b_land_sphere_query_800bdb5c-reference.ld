/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d17b_land_sphere_query_800bdb5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d17b_land_group_intersect_800b1410 = 0x800b1410;
d17b_land_groups_8043bb64 = 0x8043bb64;
d17b_land_select_mask_800bd53c = 0x800bd53c;
s9_update_value_80178d28 = 0x80178d28;
w3d_constructor_native_cast_80342a78 = 0x80342a78;
SECTIONS {
  .text.d17b_land_sphere_query_800bdb5c 0x800bdb5c : { *(.text.d17b_land_sphere_query_800bdb5c) }
  .sdata 0x804ae5dc (NOLOAD) : {
    . = 0x0; d17b_land_query_result_804ae5dc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
