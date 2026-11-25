/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_construct_resource_set_80186b5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801902e8 = 0x801902e8;
fn_8020b680 = 0x8020b680;
lbl_803a7b08 = 0x803a7b08;
lbl_80412da8 = 0x80412da8;
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
  .text.s9_construct_resource_set_80186b5c 0x80186b5c : { *(.text.s9_construct_resource_set_80186b5c) }
  .sdata 0x804ab688 (NOLOAD) : {
    . = 0x0; lbl_804ab688 = .;
    . = 0x4b7c; lbl_804b0204 = .;
    . = 0x4b80; lbl_804b0208 = .;
    . = 0x4b84; lbl_804b020c = .;
    . = 0x4b88; lbl_804b0210 = .;
    . = 0x4b8c; lbl_804b0214 = .;
    . = 0x4b90; lbl_804b0218 = .;
    . = 0x4b94; lbl_804b021c = .;
    . = 0x4b98; lbl_804b0220 = .;
    . = 0x4b9c; lbl_804b0224 = .;
    . = 0x4ba0; lbl_804b0228 = .;
    . = 0x4ba4; lbl_804b022c = .;
    . = 0x4ba8; lbl_804b0230 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
