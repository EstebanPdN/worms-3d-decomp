/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_erase_item_801f804c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802eeef4 = 0x802eeef4;
fn_80359cec = 0x80359cec;
SECTIONS {
  .text.w3d_s21_erase_item_801f804c 0x801f804c : { *(.text.w3d_s21_erase_item_801f804c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
