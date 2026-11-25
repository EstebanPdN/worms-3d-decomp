/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d43p_polynomial_real_roots_801975b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
eval_80197244 = 0x80197244;
w3d_cc24b_root_bracket_801974f8 = 0x801974f8;
SECTIONS {
  .text.d43p_polynomial_real_roots_801975b4 0x801975b4 : { *(.text.d43p_polynomial_real_roots_801975b4) }
  .rodata 0x803a84f8 : { *(.rodata) }
  .sdata 0x804ab6e4 (NOLOAD) : {
    . = 0x0; lbl_804ab6e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
