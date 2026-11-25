/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_elapsed_801fe4d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80300aa0 = 0x80300aa0;
SECTIONS {
  .text.w3d_s21_elapsed_801fe4d8 0x801fe4d8 : { *(.text.w3d_s21_elapsed_801fe4d8) }
  .sdata 0x804b0628 (NOLOAD) : {
    . = 0x0; lbl_804b0628 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
