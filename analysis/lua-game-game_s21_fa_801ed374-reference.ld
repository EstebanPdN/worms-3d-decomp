/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_write_text_801ed374)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__7S21TextPCc = 0x8020bb54;
fn_8020c5c4__FP7S21Text = 0x8020c5c4;
fn_80341588__FP7S21Text = 0x80341588;
SECTIONS {
  .text.w3d_s21_write_text_801ed374 0x801ed374 : { *(.text.w3d_s21_write_text_801ed374) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
