/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802c1030)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
fn_802C1248 = 0x802c1248;
fn_802C1398 = 0x802c1398;
fn_802C1C90 = 0x802c1c90;
lbl_803D84C0 = 0x803d84c0;
lbl_803D84C4 = 0x803d84c4;
SECTIONS {
  .text.w3d_auto_802c1030 0x802c1030 : { *(.text.w3d_auto_802c1030) }
  .sdata 0x804abb5c (NOLOAD) : {
    . = 0x0; lbl_804ABB5C = .;
    . = 0x550c; lbl_804B1068 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
