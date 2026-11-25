/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801d6aac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803AF654 = 0x803af654;
lbl_803AF658 = 0x803af658;
lbl_803AF65C = 0x803af65c;
lbl_803AF660 = 0x803af660;
lbl_803AF664 = 0x803af664;
lbl_803AF668 = 0x803af668;
SECTIONS {
  .text.w3d_auto_801d6aac 0x801d6aac : { *(.text.w3d_auto_801d6aac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
