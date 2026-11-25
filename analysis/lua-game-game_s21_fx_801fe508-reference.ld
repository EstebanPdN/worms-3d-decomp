/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_to_ticks_801fe508)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80000000 = 0x80000000;
SECTIONS {
  .text.w3d_s21_to_ticks_801fe508 0x801fe508 : { *(.text.w3d_s21_to_ticks_801fe508) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
