/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_repeat_request_802cd220)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802cc0ac = 0x802cc0ac;
fn_802cd128 = 0x802cd128;
SECTIONS {
  .text.w3d_s21_repeat_request_802cd220 0x802cd220 : { *(.text.w3d_s21_repeat_request_802cd220) }
  .sdata 0x804abcd4 (NOLOAD) : {
    . = 0x0; lbl_804abcd4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
