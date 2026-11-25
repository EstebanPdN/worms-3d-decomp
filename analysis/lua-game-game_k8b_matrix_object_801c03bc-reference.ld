/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_matrix_object_801c03bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80414e70 = 0x80414e70;
lbl_8045e708 = 0x8045e708;
w3d_ctor_801b529c = 0x801b529c;
SECTIONS {
  .text.w3d_k8b_matrix_object_801c03bc 0x801c03bc : { *(.text.w3d_k8b_matrix_object_801c03bc) }
  .sdata 0x804b05ac (NOLOAD) : {
    . = 0x0; lbl_804b05ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
