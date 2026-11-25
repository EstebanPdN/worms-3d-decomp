/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_static_identity3_801f675c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803b1644 = 0x803b1644;
lbl_803b1648 = 0x803b1648;
lbl_8045e6e4 = 0x8045e6e4;
SECTIONS {
  .text.w3d_s21_static_identity3_801f675c 0x801f675c : { *(.text.w3d_s21_static_identity3_801f675c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
