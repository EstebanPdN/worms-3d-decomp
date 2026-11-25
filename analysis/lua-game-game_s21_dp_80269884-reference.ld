/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_set_mode_80269884)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8026a16c = 0x8026a16c;
fn_802b0990 = 0x802b0990;
fn_802b1258 = 0x802b1258;
SECTIONS {
  .text.w3d_s21_set_mode_80269884 0x80269884 : { *(.text.w3d_s21_set_mode_80269884) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
