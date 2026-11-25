/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801d6a4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803AF644 = 0x803af644;
lbl_803AF648 = 0x803af648;
lbl_803AF64C = 0x803af64c;
lbl_803AF650 = 0x803af650;
SECTIONS {
  .text.w3d_auto_801d6a4c 0x801d6a4c : { *(.text.w3d_auto_801d6a4c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
