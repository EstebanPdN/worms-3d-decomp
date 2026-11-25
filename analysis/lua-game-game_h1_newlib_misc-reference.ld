/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(srand)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcmp = 0x802ef234;
w3d_lconv_803dbdb4 = 0x803dbdb4;
SECTIONS {
  .text.srand 0x802ee7d0 : { *(.text.srand) }
  .text.rand 0x802ee7dc : { *(.text.rand) }
  .text.strcoll 0x802ef2dc : { *(.text.strcoll) }
  .text._localeconv_r 0x802f31f8 : { *(.text._localeconv_r) }
  .text.localeconv 0x802f3204 : { *(.text.localeconv) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; w3d_sda_impure_ptr_804ac570 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
