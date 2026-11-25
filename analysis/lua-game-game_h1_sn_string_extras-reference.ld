/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(strlwr)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ctype_803db449 = 0x803db449;
w3d_itoa_digits_80404b08 = 0x80404b08;
SECTIONS {
  .text.strlwr 0x802efa2c : { *(.text.strlwr) }
  .text.strrchr 0x802efcc8 : { *(.text.strrchr) }
  .text.w3d_round_up_digits_802efff4 0x802efff4 : { *(.text.w3d_round_up_digits_802efff4) }
  .text.strrev 0x802f0050 : { *(.text.strrev) }
  .text.itoa 0x802f009c : { *(.text.itoa) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
