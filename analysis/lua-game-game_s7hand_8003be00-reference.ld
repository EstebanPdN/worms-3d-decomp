/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8003be00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8003C3BC = 0x8003c3bc;
fn_8003C938 = 0x8003c938;
fn_8003CDCC = 0x8003cdcc;
fn_8003CE0C = 0x8003ce0c;
fn_8003CF5C = 0x8003cf5c;
fn_8003CF8C = 0x8003cf8c;
fn_8003CFBC = 0x8003cfbc;
fn_800FC6DC = 0x800fc6dc;
fn_80165254 = 0x80165254;
fn_80178C48 = 0x80178c48;
fn_80181640 = 0x80181640;
fn_80181CCC = 0x80181ccc;
fn_80343584 = 0x80343584;
lbl_803743BC = 0x803743bc;
lbl_803743C0 = 0x803743c0;
SECTIONS {
  .text.w3d_auto_8003be00 0x8003be00 : { *(.text.w3d_auto_8003be00) }
  .sdata 0x804aa928 (NOLOAD) : {
    . = 0x0; lbl_804AA928 = .;
    . = 0x118c; lbl_804ABAB4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
