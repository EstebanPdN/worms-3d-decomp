/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d15f_property_set_kind0_8034bf50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d15f_allocate_801fe1d8 = 0x801fe1d8;
d15f_construct_kind0_80178bc4 = 0x80178bc4;
d15f_construct_kind1_80178c98 = 0x80178c98;
d15f_construct_kind2_80178d6c = 0x80178d6c;
d15f_construct_kind3_80178e40 = 0x80178e40;
d15f_construct_kind6_8017917c = 0x8017917c;
d15f_construct_kind7_80178ed0 = 0x80178ed0;
d15f_lookup_80177eb0 = 0x80177eb0;
d15f_update_kind0_80178c54 = 0x80178c54;
d15f_update_kind1_80178d28 = 0x80178d28;
d15f_update_kind2_80178dfc = 0x80178dfc;
d15f_update_kind3_80178fa4 = 0x80178fa4;
d15f_update_kind6_801792a4 = 0x801792a4;
d15f_update_kind7_80178f60 = 0x80178f60;
d15f_view_kind0_803426b4 = 0x803426b4;
d15f_view_kind1_80342a78 = 0x80342a78;
d15f_view_kind2_80342a74 = 0x80342a74;
d15f_view_kind3_80342fa4 = 0x80342fa4;
d15f_view_kind6_80343858 = 0x80343858;
d15f_view_kind7_80343df4 = 0x80343df4;
SECTIONS {
  .text.d15f_property_set_kind0_8034bf50 0x8034bf50 : { *(.text.d15f_property_set_kind0_8034bf50) }
  .text.d15f_property_set_kind1_8034c148 0x8034c148 : { *(.text.d15f_property_set_kind1_8034c148) }
  .text.d15f_property_set_kind2_8034c340 0x8034c340 : { *(.text.d15f_property_set_kind2_8034c340) }
  .text.d15f_property_set_kind3_8034c538 0x8034c538 : { *(.text.d15f_property_set_kind3_8034c538) }
  .text.d15f_property_set_kind6_8034c730 0x8034c730 : { *(.text.d15f_property_set_kind6_8034c730) }
  .text.d15f_property_set_kind7_8034c928 0x8034c928 : { *(.text.d15f_property_set_kind7_8034c928) }
  .sdata 0x804ab5b0 (NOLOAD) : {
    . = 0x0; d15f_created_count_804ab5b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
