/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_array_801b4f60)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eff8c = 0x801eff8c;
lbl_803aace8 = 0x803aace8;
lbl_803abd5c = 0x803abd5c;
lbl_803ad870 = 0x803ad870;
lbl_803fe4c4 = 0x803fe4c4;
lbl_803fe570 = 0x803fe570;
lbl_803fe63c = 0x803fe63c;
lbl_8045cecc = 0x8045cecc;
lbl_8045d1d8 = 0x8045d1d8;
lbl_8045d64c = 0x8045d64c;
lbl_8045e004 = 0x8045e004;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_array_801b4f60 0x801b4f60 : { *(.text.w3d_s10_register_array_801b4f60) }
  .text.w3d_s10_register_array_801be5a0 0x801be5a0 : { *(.text.w3d_s10_register_array_801be5a0) }
  .text.w3d_s10_register_array_801c9728 0x801c9728 : { *(.text.w3d_s10_register_array_801c9728) }
  .sdata 0x804b0360 (NOLOAD) : {
    . = 0x0; lbl_804b0360 = .;
    . = 0x9c; lbl_804b03fc = .;
    . = 0x180; lbl_804b04e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
