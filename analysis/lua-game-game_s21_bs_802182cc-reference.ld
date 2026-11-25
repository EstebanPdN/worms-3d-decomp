/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_destroy_802182cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8021837c = 0x8021837c;
lbl_804197d8 = 0x804197d8;
SECTIONS {
  .text.w3d_s21_destroy_802182cc 0x802182cc : { *(.text.w3d_s21_destroy_802182cc) }
  .sdata 0x804abaa4 (NOLOAD) : {
    . = 0x0; lbl_804abaa4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
