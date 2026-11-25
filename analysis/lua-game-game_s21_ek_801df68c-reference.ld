/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_sample_801df68c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803b03ac = 0x803b03ac;
lbl_803b03b8 = 0x803b03b8;
SECTIONS {
  .text.w3d_s21_sample_801df68c 0x801df68c : { *(.text.w3d_s21_sample_801df68c) }
  .rodata 0x803b03b0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
