/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc19b_register_properties_8024d658)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ebbb8 = 0x801ebbb8;
fn_801ecc6c = 0x801ecc6c;
fn_801efd34 = 0x801efd34;
fn_801efd98 = 0x801efd98;
lbl_803c4ff4 = 0x803c4ff4;
lbl_803c5008 = 0x803c5008;
lbl_803c5028 = 0x803c5028;
lbl_803c504c = 0x803c504c;
lbl_803c5070 = 0x803c5070;
lbl_803c50a8 = 0x803c50a8;
lbl_8045ed1c = 0x8045ed1c;
lbl_8045ed34 = 0x8045ed34;
lbl_80464edc = 0x80464edc;
lbl_80464ef0 = 0x80464ef0;
lbl_80464f04 = 0x80464f04;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_cc19b_register_properties_8024d658 0x8024d658 : { *(.text.w3d_cc19b_register_properties_8024d658) }
  .sdata 0x804b08c0 (NOLOAD) : {
    . = 0x0; lbl_804b08c0 = .;
    . = 0x4; lbl_804b08c4 = .;
    . = 0x8; lbl_804b08c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
