/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_counter_poll_801e4fcc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_803229bc = 0x803229bc;
SECTIONS {
  .text.w3d_s21_counter_poll_801e4fcc 0x801e4fcc : { *(.text.w3d_s21_counter_poll_801e4fcc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
