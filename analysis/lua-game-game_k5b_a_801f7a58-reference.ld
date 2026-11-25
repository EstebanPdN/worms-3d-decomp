/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k5b_axis_vectors_sinit_801f7a58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8045e788 = 0x8045e788;
lbl_8045e794 = 0x8045e794;
lbl_8045e7a0 = 0x8045e7a0;
lbl_8045e7ac = 0x8045e7ac;
SECTIONS {
  .text.w3d_k5b_axis_vectors_sinit_801f7a58 0x801f7a58 : { *(.text.w3d_k5b_axis_vectors_sinit_801f7a58) }
  .rodata 0x803b1838 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
