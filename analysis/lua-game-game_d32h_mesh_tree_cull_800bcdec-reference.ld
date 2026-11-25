/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32h_mesh_tree_cull_800bcdec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80382ce4 = 0x80382ce4;
lbl_8043add8 = 0x8043add8;
lbl_8043ade4 = 0x8043ade4;
lbl_8043adf0 = 0x8043adf0;
lbl_8043adfc = 0x8043adfc;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d32h_mesh_tree_cull_800bcdec 0x800bcdec : { *(.text.d32h_mesh_tree_cull_800bcdec) }
  .rodata 0x80382ce8 : { *(.rodata) }
  .sdata 0x804b181c (NOLOAD) : {
    . = 0x0; lbl_804b181c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
