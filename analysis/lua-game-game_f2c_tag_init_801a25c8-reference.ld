/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f2c_tag_init_801a25c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80411ac0 = 0x80411ac0;
lbl_80413a00 = 0x80413a00;
SECTIONS {
  .text.f2c_tag_init_801a25c8 0x801a25c8 : { *(.text.f2c_tag_init_801a25c8) }
  .sdata 0x804ab750 (NOLOAD) : {
    . = 0x0; lbl_804ab750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
