/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_release_singleton_802002fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s21_release_singleton_802002fc 0x802002fc : { *(.text.w3d_s21_release_singleton_802002fc) }
  .sdata 0x804b063c (NOLOAD) : {
    . = 0x0; lbl_804b063c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
