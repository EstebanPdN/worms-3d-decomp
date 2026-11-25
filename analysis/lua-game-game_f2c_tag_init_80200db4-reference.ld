/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f2c_tag_init_80200db4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80418df0 = 0x80418df0;
lbl_80418eb8 = 0x80418eb8;
SECTIONS {
  .text.f2c_tag_init_80200db4 0x80200db4 : { *(.text.f2c_tag_init_80200db4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
