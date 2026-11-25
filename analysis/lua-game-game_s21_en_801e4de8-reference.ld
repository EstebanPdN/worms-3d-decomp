/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_stop_801e4de8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e4fcc = 0x801e4fcc;
fn_803228f8 = 0x803228f8;
SECTIONS {
  .text.w3d_s21_stop_801e4de8 0x801e4de8 : { *(.text.w3d_s21_stop_801e4de8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
