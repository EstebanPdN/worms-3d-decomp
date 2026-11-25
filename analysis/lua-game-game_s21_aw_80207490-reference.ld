/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_acquire_cleared_80207490)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802099f8 = 0x802099f8;
SECTIONS {
  .text.w3d_s21_acquire_cleared_80207490 0x80207490 : { *(.text.w3d_s21_acquire_cleared_80207490) }
  .sdata 0x804b064c (NOLOAD) : {
    . = 0x0; lbl_804b064c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
