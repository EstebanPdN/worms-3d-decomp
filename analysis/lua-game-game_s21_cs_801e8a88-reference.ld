/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_construct_801e8a88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020fbd0 = 0x8020fbd0;
lbl_80417190 = 0x80417190;
lbl_804171b8 = 0x804171b8;
SECTIONS {
  .text.w3d_s21_construct_801e8a88 0x801e8a88 : { *(.text.w3d_s21_construct_801e8a88) }
  .sdata 0x804b18e0 (NOLOAD) : {
    . = 0x0; lbl_804b18e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
