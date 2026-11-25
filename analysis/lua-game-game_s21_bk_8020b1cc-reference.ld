/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_destroy_global_8020b1cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80210990 = 0x80210990;
lbl_804181c0 = 0x804181c0;
lbl_804632e8 = 0x804632e8;
SECTIONS {
  .text.w3d_s21_destroy_global_8020b1cc 0x8020b1cc : { *(.text.w3d_s21_destroy_global_8020b1cc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
