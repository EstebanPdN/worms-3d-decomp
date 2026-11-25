/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80267fe8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8026710C = 0x8026710c;
fn_80268568 = 0x80268568;
fn_802B16C4 = 0x802b16c4;
lbl_803CB71C = 0x803cb71c;
lbl_803CB720 = 0x803cb720;
SECTIONS {
  .text.w3d_auto_80267fe8 0x80267fe8 : { *(.text.w3d_auto_80267fe8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
