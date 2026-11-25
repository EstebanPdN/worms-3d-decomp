/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32e_static_init_tables_801fd90c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8045e944 = 0x8045e944;
lbl_8045e970 = 0x8045e970;
SECTIONS {
  .text.w3d_d32e_static_init_tables_801fd90c 0x801fd90c : { *(.text.w3d_d32e_static_init_tables_801fd90c) }
  .sdata 0x804b05e0 (NOLOAD) : {
    . = 0x0; lbl_804b05e0 = .;
    . = 0x4; lbl_804b05e4 = .;
    . = 0x8; lbl_804b05e8 = .;
    . = 0xc; lbl_804b05ec = .;
    . = 0x10; lbl_804b05f0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
