/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_construct_named_801c2168)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ea0ec = 0x801ea0ec;
fn_801ec0f8 = 0x801ec0f8;
fn_8020c5c0 = 0x8020c5c0;
fn_80341884 = 0x80341884;
lbl_803b9544 = 0x803b9544;
lbl_803b9574 = 0x803b9574;
lbl_803b95a4 = 0x803b95a4;
lbl_803b95d4 = 0x803b95d4;
lbl_80414d58 = 0x80414d58;
lbl_804b06a0 = 0x804b06a0;
SECTIONS {
  .text.w3d_construct_named_801c2168 0x801c2168 : { *(.text.w3d_construct_named_801c2168) }
  .text.w3d_get_indexed_801fbe9c 0x801fbe9c : { *(.text.w3d_get_indexed_801fbe9c) }
  .text.w3d_get_indexed_8020a7f8 0x8020a7f8 : { *(.text.w3d_get_indexed_8020a7f8) }
  .text.w3d_register_bindings_8022a058 0x8022a058 : { *(.text.w3d_register_bindings_8022a058) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
