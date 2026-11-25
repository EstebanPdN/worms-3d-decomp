/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f2c_tag_init_801e34b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803b0658 = 0x803b0658;
lbl_803b065c = 0x803b065c;
lbl_80416a90 = 0x80416a90;
lbl_80416ee0 = 0x80416ee0;
SECTIONS {
  .text.f2c_tag_init_801e34b0 0x801e34b0 : { *(.text.f2c_tag_init_801e34b0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
