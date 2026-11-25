/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_dump_request_802cd198)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__7S21Text = 0x803426b8;
fn_8020c5c4__FP7S21Text = 0x8020c5c4;
fn_802cc01c__FPvPci = 0x802cc01c;
fn_802cd128__FP7S21Text = 0x802cd128;
fn_80341588__FP7S21Text = 0x80341588;
request__7S21Textii = 0x802cc0ac;
SECTIONS {
  .text.w3d_s21_dump_request_802cd198 0x802cd198 : { *(.text.w3d_s21_dump_request_802cd198) }
  .sdata 0x804abcd4 (NOLOAD) : {
    . = 0x0; lbl_804abcd4 = .;
    . = 0x10; lbl_804abce4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
