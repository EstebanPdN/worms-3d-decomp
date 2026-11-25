/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_swap_restore_802156c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80217f8c = 0x80217f8c;
SECTIONS {
  .text.w3d_s21_swap_restore_802156c8 0x802156c8 : { *(.text.w3d_s21_swap_restore_802156c8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
