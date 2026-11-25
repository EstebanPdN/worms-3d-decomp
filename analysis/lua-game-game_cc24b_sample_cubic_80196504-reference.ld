/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc24b_sample_cubic_80196504)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801975b4 = 0x801975b4;
lbl_803a84b0 = 0x803a84b0;
lbl_803a84b4 = 0x803a84b4;
lbl_804a91d8 = 0x804a91d8;
lbl_804a91e8 = 0x804a91e8;
SECTIONS {
  .text.w3d_cc24b_sample_cubic_80196504 0x80196504 : { *(.text.w3d_cc24b_sample_cubic_80196504) }
  .sdata 0x804b18c4 (NOLOAD) : {
    . = 0x0; lbl_804b18c4 = .;
    . = 0xc; lbl_804b18d0 = .;
    . = 0x10; lbl_804b18d4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
