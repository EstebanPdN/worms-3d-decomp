/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_reserve_80208ebc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fe0b8 = 0x801fe0b8;
fn_80213750 = 0x80213750;
SECTIONS {
  .text.w3d_s21_reserve_80208ebc 0x80208ebc : { *(.text.w3d_s21_reserve_80208ebc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
