/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_start_voice_801e4ce0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80322938 = 0x80322938;
SECTIONS {
  .text.w3d_s21_start_voice_801e4ce0 0x801e4ce0 : { *(.text.w3d_s21_start_voice_801e4ce0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
