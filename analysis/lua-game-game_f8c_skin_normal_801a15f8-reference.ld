/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f8c_skin_normal_801a15f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803a9b50 = 0x803a9b50;
lbl_803a9b54 = 0x803a9b54;
SECTIONS {
  .text.f8c_skin_normal_801a15f8 0x801a15f8 : { *(.text.f8c_skin_normal_801a15f8) }
  .sdata 0x804ab744 (NOLOAD) : {
    . = 0x0; lbl_804ab744 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
