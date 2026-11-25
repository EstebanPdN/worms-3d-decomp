/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d33b_cell_mask_walk_80086660)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
kFloatOne = 0x8037d0b4;
w3d_auto_80086514 = 0x80086514;
w3d_auto_8008659c = 0x8008659c;
SECTIONS {
  .text.d33b_cell_mask_walk_80086660 0x80086660 : { *(.text.d33b_cell_mask_walk_80086660) }
  .sdata 0x804addec (NOLOAD) : {
    . = 0x0; lbl_804addec = .;
    . = 0x4; lbl_804addf0 = .;
    . = 0x8; lbl_804addf4 = .;
    . = 0xc; lbl_804addf8 = .;
    . = 0x10; lbl_804addfc = .;
    . = 0x14; lbl_804ade00 = .;
    . = 0x18; lbl_804ade04 = .;
    . = 0x1c; lbl_804ade08 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
