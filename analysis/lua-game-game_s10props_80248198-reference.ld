/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_80248198)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efff0 = 0x801efff0;
fn_801f2100 = 0x801f2100;
lbl_803c41b8 = 0x803c41b8;
lbl_803c41c0 = 0x803c41c0;
lbl_803c41cc = 0x803c41cc;
lbl_8045e23c = 0x8045e23c;
lbl_8045ed94 = 0x8045ed94;
lbl_80464dd8 = 0x80464dd8;
lbl_80464dec = 0x80464dec;
lbl_80464e00 = 0x80464e00;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_80248198 0x80248198 : { *(.text.w3d_s10_register_properties_80248198) }
  .sdata 0x804b088c (NOLOAD) : {
    . = 0x0; lbl_804b088c = .;
    . = 0x4; lbl_804b0890 = .;
    . = 0x8; lbl_804b0894 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
