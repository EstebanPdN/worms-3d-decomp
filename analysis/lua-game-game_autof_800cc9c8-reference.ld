/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800cc9c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800CCAF8 = 0x800ccaf8;
fn_800CCBF4 = 0x800ccbf4;
fn_80126034 = 0x80126034;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
lbl_80387DB4 = 0x80387db4;
lbl_80387DC4 = 0x80387dc4;
SECTIONS {
  .text.w3d_auto_800cc9c8 0x800cc9c8 : { *(.text.w3d_auto_800cc9c8) }
  .sdata 0x804ae84c (NOLOAD) : {
    . = 0x0; lbl_804AE84C = .;
    . = 0x8; lbl_804AE854 = .;
    . = 0x2f3c; lbl_804B1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
