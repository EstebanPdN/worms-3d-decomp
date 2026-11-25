/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_set_vector_if_changed_80178fa4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178b5c = 0x80178b5c;
fn_8017ce10 = 0x8017ce10;
fn_8017d288 = 0x8017d288;
fn_8020bd38 = 0x8020bd38;
lbl_804a8dd8 = 0x804a8dd8;
SECTIONS {
  .text.w3d_s20_set_vector_if_changed_80178fa4 0x80178fa4 : { *(.text.w3d_s20_set_vector_if_changed_80178fa4) }
  .text.w3d_s20_clear_tables_8017ccdc 0x8017ccdc : { *(.text.w3d_s20_clear_tables_8017ccdc) }
  .text.w3d_s20_register_item_8017cd80 0x8017cd80 : { *(.text.w3d_s20_register_item_8017cd80) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
