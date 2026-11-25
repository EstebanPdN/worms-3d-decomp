/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_construct_801f6034)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803b1614 = 0x803b1614;
lbl_803b1618 = 0x803b1618;
lbl_803b1650 = 0x803b1650;
lbl_803b1654 = 0x803b1654;
SECTIONS {
  .text.w3d_construct_801f6034 0x801f6034 : { *(.text.w3d_construct_801f6034) }
  .text.w3d_construct_801f67e0 0x801f67e0 : { *(.text.w3d_construct_801f67e0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
