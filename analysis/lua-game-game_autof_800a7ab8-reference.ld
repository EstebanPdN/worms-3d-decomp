/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800a7ab8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80035714 = 0x80035714;
fn_800F8A48 = 0x800f8a48;
fn_8015F65C = 0x8015f65c;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_80165254 = 0x80165254;
lbl_80381990 = 0x80381990;
lbl_80381998 = 0x80381998;
lbl_8040DB38 = 0x8040db38;
SECTIONS {
  .text.w3d_auto_800a7ab8 0x800a7ab8 : { *(.text.w3d_auto_800a7ab8) }
  .text.w3d_auto_800a9b18 0x800a9b18 : { *(.text.w3d_auto_800a9b18) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; lbl_804AA8C8 = .;
    . = 0x3a54; lbl_804AE31C = .;
    . = 0x6e8c; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
