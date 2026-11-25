/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_properties_801c04f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eff8c = 0x801eff8c;
fn_801f0d2c = 0x801f0d2c;
lbl_803ac3a8 = 0x803ac3a8;
lbl_803ac3bc = 0x803ac3bc;
lbl_803fe588 = 0x803fe588;
lbl_8045d250 = 0x8045d250;
lbl_8045e004 = 0x8045e004;
lbl_8045e708 = 0x8045e708;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_properties_801c04f8 0x801c04f8 : { *(.text.w3d_s20_register_properties_801c04f8) }
  .sdata 0x804b0414 (NOLOAD) : {
    . = 0x0; lbl_804b0414 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
