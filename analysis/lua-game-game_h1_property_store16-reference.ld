/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_property_store16_assign_8035e2c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memcmp = 0x802eedc0;
w3d_property_default16_804641cc = 0x804641cc;
w3d_property_insert_802078b4 = 0x802078b4;
w3d_s21_find_data_80207950 = 0x80207950;
SECTIONS {
  .text.w3d_property_store16_assign_8035e2c0 0x8035e2c0 : { *(.text.w3d_property_store16_assign_8035e2c0) }
  .text.w3d_property_store16_same_8035e348 0x8035e348 : { *(.text.w3d_property_store16_same_8035e348) }
  .text.w3d_property_store16_lacks_8035e3d0 0x8035e3d0 : { *(.text.w3d_property_store16_lacks_8035e3d0) }
  .text.w3d_property_store16_set_8035e404 0x8035e404 : { *(.text.w3d_property_store16_set_8035e404) }
  .text.w3d_property_store16_get_8035e468 0x8035e468 : { *(.text.w3d_property_store16_get_8035e468) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
