/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_clear_texts_802067e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020c5c4 = 0x8020c5c4;
fn_80210afc = 0x80210afc;
fn_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_s21_clear_texts_802067e4 0x802067e4 : { *(.text.w3d_s21_clear_texts_802067e4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
