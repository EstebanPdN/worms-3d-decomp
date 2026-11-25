/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24j_construct_resource_set_8016fc7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801902e8 = 0x801902e8;
fn_801fe1d8 = 0x801fe1d8;
fn_8020b680 = 0x8020b680;
fn_802109dc = 0x802109dc;
lbl_803a65a8 = 0x803a65a8;
lbl_80412008 = 0x80412008;
lbl_80414210 = 0x80414210;
lbl_80415bb0 = 0x80415bb0;
lbl_80415c00 = 0x80415c00;
lbl_80415c10 = 0x80415c10;
lbl_80415c30 = 0x80415c30;
lbl_80415c80 = 0x80415c80;
lbl_80415cb0 = 0x80415cb0;
lbl_804166b0 = 0x804166b0;
lbl_80416750 = 0x80416750;
SECTIONS {
  .text.d24j_construct_resource_set_8016fc7c 0x8016fc7c : { *(.text.d24j_construct_resource_set_8016fc7c) }
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
