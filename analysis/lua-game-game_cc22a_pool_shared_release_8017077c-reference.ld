/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc22a_pool_shared_release_8017077c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80190384 = 0x80190384;
fn_80210abc = 0x80210abc;
fn_8034be70 = 0x8034be70;
lbl_80412008 = 0x80412008;
SECTIONS {
  .text.cc22a_pool_shared_release_8017077c 0x8017077c : { *(.text.cc22a_pool_shared_release_8017077c) }
  .sdata 0x804b0124 (NOLOAD) : {
    . = 0x0; lbl_804b0124 = .;
    . = 0x4; lbl_804b0128 = .;
    . = 0x8; lbl_804b012c = .;
    . = 0xc; lbl_804b0130 = .;
    . = 0x10; lbl_804b0134 = .;
    . = 0x14; lbl_804b0138 = .;
    . = 0x18; lbl_804b013c = .;
    . = 0x1c; lbl_804b0140 = .;
    . = 0x20; lbl_804b0144 = .;
    . = 0x24; lbl_804b0148 = .;
    . = 0x28; lbl_804b014c = .;
    . = 0x2c; lbl_804b0150 = .;
    . = 0x1774; lbl_804b1898 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
