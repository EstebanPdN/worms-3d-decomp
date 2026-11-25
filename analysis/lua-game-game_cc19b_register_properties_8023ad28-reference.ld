/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc19b_register_properties_8023ad28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ebf38 = 0x801ebf38;
fn_801ecc6c = 0x801ecc6c;
fn_801eff8c = 0x801eff8c;
lbl_803bb86c = 0x803bb86c;
lbl_803bb884 = 0x803bb884;
lbl_803bb8b8 = 0x803bb8b8;
lbl_803bb8e0 = 0x803bb8e0;
lbl_803bb914 = 0x803bb914;
lbl_803bb94c = 0x803bb94c;
lbl_803bb984 = 0x803bb984;
lbl_803bb9b4 = 0x803bb9b4;
lbl_803bb9ec = 0x803bb9ec;
lbl_803bba24 = 0x803bba24;
lbl_803bba58 = 0x803bba58;
lbl_80400bfc = 0x80400bfc;
lbl_8045e004 = 0x8045e004;
lbl_80464c20 = 0x80464c20;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_cc19b_register_properties_8023ad28 0x8023ad28 : { *(.text.w3d_cc19b_register_properties_8023ad28) }
  .sdata 0x804b0834 (NOLOAD) : {
    . = 0x0; lbl_804b0834 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
