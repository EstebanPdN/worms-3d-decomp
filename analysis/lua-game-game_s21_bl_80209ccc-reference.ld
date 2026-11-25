/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_construct_80209ccc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80209e08 = 0x80209e08;
SECTIONS {
  .text.w3d_s21_construct_80209ccc 0x80209ccc : { *(.text.w3d_s21_construct_80209ccc) }
  .sdata 0x804ab9ec (NOLOAD) : {
    . = 0x0; lbl_804ab9ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
