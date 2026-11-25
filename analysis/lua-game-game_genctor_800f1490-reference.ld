/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_construct_800f1490)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803afe2c = 0x803afe2c;
SECTIONS {
  .text.w3d_construct_800f1490 0x800f1490 : { *(.text.w3d_construct_800f1490) }
  .text.w3d_construct_801daf38 0x801daf38 : { *(.text.w3d_construct_801daf38) }
  .text.w3d_construct_801e6ea8 0x801e6ea8 : { *(.text.w3d_construct_801e6ea8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
