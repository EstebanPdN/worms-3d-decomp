/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802c4e7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803D8814 = 0x803d8814;
lbl_803D8818 = 0x803d8818;
SECTIONS {
  .text.w3d_auto_802c4e7c 0x802c4e7c : { *(.text.w3d_auto_802c4e7c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
