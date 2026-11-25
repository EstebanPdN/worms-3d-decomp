/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f1c_tag_init_801fc518)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_804182d0 = 0x804182d0;
lbl_804183b0 = 0x804183b0;
SECTIONS {
  .text.f1c_tag_init_801fc518 0x801fc518 : { *(.text.f1c_tag_init_801fc518) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
