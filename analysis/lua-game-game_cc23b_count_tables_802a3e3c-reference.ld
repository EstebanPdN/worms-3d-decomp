/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc23b_count_tables_802a3e3c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_804021e8 = 0x804021e8;
lbl_804024a4 = 0x804024a4;
lbl_80403980 = 0x80403980;
lbl_804039b0 = 0x804039b0;
lbl_804abc28 = 0x804abc28;
SECTIONS {
  .text.w3d_cc23b_count_tables_802a3e3c 0x802a3e3c : { *(.text.w3d_cc23b_count_tables_802a3e3c) }
  .sdata 0x804b0eb4 (NOLOAD) : {
    . = 0x0; lbl_804b0eb4 = .;
    . = 0x4; lbl_804b0eb8 = .;
    . = 0x8; lbl_804b0ebc = .;
    . = 0xc; lbl_804b0ec0 = .;
    . = 0x10; lbl_804b0ec4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
