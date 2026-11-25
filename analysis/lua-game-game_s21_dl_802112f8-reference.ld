/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_set_text_then_copy_802112f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020bb2c__FPv = 0x8020bb2c;
fn_8020c5c0__FP7S21Text = 0x8020c5c0;
fn_8020c5c4__FP7S21Text = 0x8020c5c4;
fn_80341588__FP7S21Text = 0x80341588;
fn_80341884__FP7S21Text = 0x80341884;
SECTIONS {
  .text.w3d_s21_set_text_then_copy_802112f8 0x802112f8 : { *(.text.w3d_s21_set_text_then_copy_802112f8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
