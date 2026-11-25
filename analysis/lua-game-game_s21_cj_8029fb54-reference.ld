/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_activate_8029fb54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s21_activate_8029fb54 0x8029fb54 : { *(.text.w3d_s21_activate_8029fb54) }
  .sdata 0x804abb5c (NOLOAD) : {
    . = 0x0; lbl_804abb5c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
