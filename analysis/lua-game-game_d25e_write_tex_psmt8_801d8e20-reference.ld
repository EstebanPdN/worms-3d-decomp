/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25e_write_tex_psmt8_801d8e20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803ff414 = 0x803ff414;
lbl_803ff494 = 0x803ff494;
lbl_803ff694 = 0x803ff694;
SECTIONS {
  .text.w3d_d25e_write_tex_psmt8_801d8e20 0x801d8e20 : { *(.text.w3d_d25e_write_tex_psmt8_801d8e20) }
  .sdata 0x804b0554 (NOLOAD) : {
    . = 0x0; lbl_804b0554 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
