/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_tagged_construct_80203970)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80203204 = 0x80203204;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_s21_construct_list_8020351c = 0x8020351c;
w3d_vtable_80418f88 = 0x80418f88;
w3d_vtable_80419038 = 0x80419038;
SECTIONS {
  .text.w3d_tagged_construct_80203970 0x80203970 : { *(.text.w3d_tagged_construct_80203970) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
