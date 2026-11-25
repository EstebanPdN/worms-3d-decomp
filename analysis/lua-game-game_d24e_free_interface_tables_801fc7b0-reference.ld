/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24e_free_interface_tables_801fc7b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802134fc = 0x802134fc;
memcpy = 0x802eee50;
table_8045e890 = 0x8045e890;
SECTIONS {
  .text.w3d_d24e_free_interface_tables_801fc7b0 0x801fc7b0 : { *(.text.w3d_d24e_free_interface_tables_801fc7b0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
