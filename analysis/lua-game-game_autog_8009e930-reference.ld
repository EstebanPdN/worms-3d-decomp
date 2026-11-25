/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8009e930)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80035714 = 0x80035714;
fn_8015F518 = 0x8015f518;
fn_8015F5A0 = 0x8015f5a0;
fn_8015F65C = 0x8015f65c;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
lbl_80380630 = 0x80380630;
lbl_80380638 = 0x80380638;
lbl_8038063C = 0x8038063c;
lbl_80380650 = 0x80380650;
lbl_80380664 = 0x80380664;
lbl_80380680 = 0x80380680;
lbl_8040DB38 = 0x8040db38;
SECTIONS {
  .text.w3d_auto_8009e930 0x8009e930 : { *(.text.w3d_auto_8009e930) }
  .text.w3d_auto_8009e998 0x8009e998 : { *(.text.w3d_auto_8009e998) }
  .text.w3d_auto_8009f464 0x8009f464 : { *(.text.w3d_auto_8009f464) }
  .text.w3d_auto_800a2098 0x800a2098 : { *(.text.w3d_auto_800a2098) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; lbl_804AA8C8 = .;
    . = 0x37f8; lbl_804AE0C0 = .;
    . = 0x3800; lbl_804AE0C8 = .;
    . = 0x3808; lbl_804AE0D0 = .;
    . = 0x3810; lbl_804AE0D8 = .;
    . = 0x3858; lbl_804AE120 = .;
    . = 0x6e8c; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
