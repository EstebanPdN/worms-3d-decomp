/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_80229d88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eff8c = 0x801eff8c;
lbl_803b9528 = 0x803b9528;
lbl_803b9530 = 0x803b9530;
lbl_804007f0 = 0x804007f0;
lbl_804007fc = 0x804007fc;
lbl_8045e004 = 0x8045e004;
lbl_80464af4 = 0x80464af4;
lbl_80464b08 = 0x80464b08;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_80229d88 0x80229d88 : { *(.text.w3d_s10_register_properties_80229d88) }
  .sdata 0x804b07fc (NOLOAD) : {
    . = 0x0; lbl_804b07fc = .;
    . = 0x4; lbl_804b0800 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
