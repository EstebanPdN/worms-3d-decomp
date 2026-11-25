/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_reset_801e6bbc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e5e74 = 0x801e5e74;
fn_801e6d30 = 0x801e6d30;
SECTIONS {
  .text.w3d_s21_reset_801e6bbc 0x801e6bbc : { *(.text.w3d_s21_reset_801e6bbc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
