/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_is_idle_801e5024)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e4fcc = 0x801e4fcc;
SECTIONS {
  .text.w3d_s21_is_idle_801e5024 0x801e5024 : { *(.text.w3d_s21_is_idle_801e5024) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
