/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d41h_trajectory_setup_cull_800b0cf8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d32h_mesh_tree_cull_800bcdec = 0x800bcdec;
lbl_8043add8 = 0x8043add8;
lbl_8043ade4 = 0x8043ade4;
lbl_8043adf0 = 0x8043adf0;
lbl_8043adfc = 0x8043adfc;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d41h_trajectory_setup_cull_800b0cf8 0x800b0cf8 : { *(.text.d41h_trajectory_setup_cull_800b0cf8) }
  .rodata 0x803823d0 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; lbl_804b1764 = .;
    . = 0x20; lbl_804b1784 = .;
    . = 0x7c; lbl_804b17e0 = .;
    . = 0xac; lbl_804b1810 = .;
    . = 0xb0; lbl_804b1814 = .;
    . = 0xb4; lbl_804b1818 = .;
    . = 0xb8; lbl_804b181c = .;
    . = 0xbc; lbl_804b1820 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
