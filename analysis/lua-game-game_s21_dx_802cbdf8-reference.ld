/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_sink_write_indexed_802cbdf8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__7S21Text = 0x803426b8;
fill__7S21Textii = 0x802cc0ac;
fn_8020c5c4__FP7S21Text = 0x8020c5c4;
fn_80341588__FP7S21Text = 0x80341588;
lbl_80473724 = 0x80473724;
SECTIONS {
  .text.w3d_s21_sink_write_indexed_802cbdf8 0x802cbdf8 : { *(.text.w3d_s21_sink_write_indexed_802cbdf8) }
  .sdata 0x804abce4 (NOLOAD) : {
    . = 0x0; lbl_804abce4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
