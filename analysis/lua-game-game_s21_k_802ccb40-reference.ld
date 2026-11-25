/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_consume_flag_802ccb40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802ccb00 = 0x802ccb00;
lbl_80403f94 = 0x80403f94;
SECTIONS {
  .text.w3d_s21_consume_flag_802ccb40 0x802ccb40 : { *(.text.w3d_s21_consume_flag_802ccb40) }
  .sdata 0x804abce4 (NOLOAD) : {
    . = 0x0; lbl_804abce4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
