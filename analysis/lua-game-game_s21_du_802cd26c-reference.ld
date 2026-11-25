/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_append_position_802cd26c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__7S21Text = 0x803426b8;
fn_8020bf2c__FPvPc = 0x8020bf2c;
fn_8020c510__FP7S21TextPCce = 0x8020c510;
fn_8020c5c4__FP7S21Text = 0x8020c5c4;
fn_80341588__FP7S21Text = 0x80341588;
lbl_803d94bc = 0x803d94bc;
SECTIONS {
  .text.w3d_s21_append_position_802cd26c 0x802cd26c : { *(.text.w3d_s21_append_position_802cd26c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
