/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_c30_turn_advance_8021c74c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800a82f0 = 0x800a82f0;
fn_800fc1f0 = 0x800fc1f0;
fn_800fc7f8 = 0x800fc7f8;
fn_801298cc = 0x801298cc;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
lbl_8040db38 = 0x8040db38;
SECTIONS {
  .text.tsonnet_c30_turn_advance_8021c74c 0x8021c74c : { *(.text.tsonnet_c30_turn_advance_8021c74c) }
  .rodata 0x803b3efc : { *(.rodata) }
  .sdata 0x804aac54 (NOLOAD) : {
    . = 0x0; lbl_804aac54 = .;
    . = 0x2f4; lbl_804aaf48 = .;
    . = 0xe60; lbl_804abab4 = .;
    . = 0x5ac0; lbl_804b0714 = .;
    . = 0x5b38; lbl_804b078c = .;
    . = 0x6b00; lbl_804b1754 = .;
    . = 0x6b34; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
