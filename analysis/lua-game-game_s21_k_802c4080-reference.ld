/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_cycle_index_802c4080)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802c38cc = 0x802c38cc;
SECTIONS {
  .text.w3d_s21_cycle_index_802c4080 0x802c4080 : { *(.text.w3d_s21_cycle_index_802c4080) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
