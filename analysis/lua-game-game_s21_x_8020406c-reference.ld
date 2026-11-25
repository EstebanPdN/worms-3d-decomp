/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_write_u16_swapped_8020406c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802047e0 = 0x802047e0;
SECTIONS {
  .text.w3d_s21_write_u16_swapped_8020406c 0x8020406c : { *(.text.w3d_s21_write_u16_swapped_8020406c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
