/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b10_retreat_finish_800ee934)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800c53a0 = 0x800c53a0;
fn_800fc1f0 = 0x800fc1f0;
fn_800fc6dc = 0x800fc6dc;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_80164cec = 0x80164cec;
fn_80165254 = 0x80165254;
fn_801797b4 = 0x801797b4;
fn_80341584 = 0x80341584;
lbl_8038bd9c = 0x8038bd9c;
lbl_8040db38 = 0x8040db38;
SECTIONS {
  .text.sol35b10_retreat_finish_800ee934 0x800ee934 : { *(.text.sol35b10_retreat_finish_800ee934) }
  .sdata 0x804aef74 (NOLOAD) : {
    . = 0x0; lbl_804aef74 = .;
    . = 0x38; lbl_804aefac = .;
    . = 0x58; lbl_804aefcc = .;
    . = 0x68; lbl_804aefdc = .;
    . = 0x70; lbl_804aefe4 = .;
    . = 0x27e0; lbl_804b1754 = .;
    . = 0x2818; lbl_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
