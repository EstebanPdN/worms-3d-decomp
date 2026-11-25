/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_register_vector_binding_801bfb00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801f0210 = 0x801f0210;
lbl_803ac0ec = 0x803ac0ec;
lbl_803ac110 = 0x803ac110;
lbl_803ac114 = 0x803ac114;
lbl_803ac248 = 0x803ac248;
lbl_803ac26c = 0x803ac26c;
lbl_803ac270 = 0x803ac270;
SECTIONS {
  .text.w3d_register_vector_binding_801bfb00 0x801bfb00 : { *(.text.w3d_register_vector_binding_801bfb00) }
  .text.w3d_register_vector_binding_801bff10 0x801bff10 : { *(.text.w3d_register_vector_binding_801bff10) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
