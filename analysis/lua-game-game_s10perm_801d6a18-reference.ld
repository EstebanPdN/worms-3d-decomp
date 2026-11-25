/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801d6a18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803AF63C = 0x803af63c;
lbl_803AF640 = 0x803af640;
SECTIONS {
  .text.w3d_auto_801d6a18 0x801d6a18 : { *(.text.w3d_auto_801d6a18) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
