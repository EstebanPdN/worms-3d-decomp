/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24h_jetpack_part_800ae7d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800e5cf0 = 0x800e5cf0;
fn_80125fdc = 0x80125fdc;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_80343584 = 0x80343584;
lbl_80382190 = 0x80382190;
lbl_803821c0 = 0x803821c0;
lbl_803821d8 = 0x803821d8;
SECTIONS {
  .text.w3d_d24h_jetpack_part_800ae7d4 0x800ae7d4 : { *(.text.w3d_d24h_jetpack_part_800ae7d4) }
  .sdata 0x804aac8c (NOLOAD) : {
    . = 0x0; lbl_804aac8c = .;
    . = 0x4; lbl_804aac90 = .;
    . = 0x8; lbl_804aac94 = .;
    . = 0x3758; lbl_804ae3e4 = .;
    . = 0x6ac8; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
