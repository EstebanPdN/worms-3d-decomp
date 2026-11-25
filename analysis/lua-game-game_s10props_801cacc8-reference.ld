/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_801cacc8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efd98 = 0x801efd98;
fn_801eff8c = 0x801eff8c;
lbl_803ad854 = 0x803ad854;
lbl_803adccc = 0x803adccc;
lbl_803add0c = 0x803add0c;
lbl_803add18 = 0x803add18;
lbl_803fe630 = 0x803fe630;
lbl_803fe654 = 0x803fe654;
lbl_8045d728 = 0x8045d728;
lbl_8045d73c = 0x8045d73c;
lbl_8045d750 = 0x8045d750;
lbl_8045d764 = 0x8045d764;
lbl_8045e004 = 0x8045e004;
lbl_8045ed34 = 0x8045ed34;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_801cacc8 0x801cacc8 : { *(.text.w3d_s10_register_properties_801cacc8) }
  .sdata 0x804b050c (NOLOAD) : {
    . = 0x0; lbl_804b050c = .;
    . = 0x4; lbl_804b0510 = .;
    . = 0x8; lbl_804b0514 = .;
    . = 0xc; lbl_804b0518 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
