/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25e_read_tex_psmct32_801d8cd4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803ff1d4 = 0x803ff1d4;
lbl_803ff254 = 0x803ff254;
SECTIONS {
  .text.w3d_d25e_read_tex_psmct32_801d8cd4 0x801d8cd4 : { *(.text.w3d_d25e_read_tex_psmct32_801d8cd4) }
  .sdata 0x804b0554 (NOLOAD) : {
    . = 0x0; lbl_804b0554 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
