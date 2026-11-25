/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_construct_8020fbd0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ffecc = 0x801ffecc;
fn_8020fe54 = 0x8020fe54;
lbl_80419598 = 0x80419598;
lbl_804195c0 = 0x804195c0;
SECTIONS {
  .text.w3d_s21_construct_8020fbd0 0x8020fbd0 : { *(.text.w3d_s21_construct_8020fbd0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
