/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_remove_handle_801e6d30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803ffe34 = 0x803ffe34;
SECTIONS {
  .text.w3d_s21_remove_handle_801e6d30 0x801e6d30 : { *(.text.w3d_s21_remove_handle_801e6d30) }
  .sdata 0x804ab874 (NOLOAD) : {
    . = 0x0; lbl_804ab874 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
