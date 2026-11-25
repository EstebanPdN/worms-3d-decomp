/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_active_worm_ctor_80021768)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8040dd08 = 0x8040dd08;
w3d_constructor_lookup_name = 0x800fc1b0;
SECTIONS {
  .text.s19_active_worm_ctor_80021768 0x80021768 : { *(.text.s19_active_worm_ctor_80021768) }
  .rodata 0x8036c014 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
