/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_owner_weight_inverse_80016978)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.s19_owner_weight_inverse_80016978 0x80016978 : { *(.text.s19_owner_weight_inverse_80016978) }
  .rodata 0x8036a690 : { *(.rodata) }
  .sdata 0x804aa6c0 (NOLOAD) : {
    . = 0x0; lbl_804aa6c0 = .;
    . = 0x40; lbl_804aa700 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
