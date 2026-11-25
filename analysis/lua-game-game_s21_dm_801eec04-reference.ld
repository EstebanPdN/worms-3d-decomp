/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_destroy_801eec04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020bb2c = 0x8020bb2c;
fn_80210990 = 0x80210990;
lbl_80411ac0 = 0x80411ac0;
lbl_80417670 = 0x80417670;
SECTIONS {
  .text.w3d_s21_destroy_801eec04 0x801eec04 : { *(.text.w3d_s21_destroy_801eec04) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
