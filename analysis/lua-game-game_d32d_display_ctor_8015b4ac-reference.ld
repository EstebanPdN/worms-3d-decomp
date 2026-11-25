/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__16Display_804110e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__13Base_8015be3c = 0x8015be3c;
__builtin_new = 0x801fe1d8;
__vt_16Display_804110e8 = 0x804110e8;
desc_80419460 = 0x80419460;
forward_8020b680 = 0x8020b680;
SECTIONS {
  .text.__16Display_804110e8 0x8015b4ac : { *(.text.__16Display_804110e8) }
  .rodata 0x803a42e0 : { *(.rodata) }
  .sdata 0x804b1880 (NOLOAD) : {
    . = 0x0; mode_804b1880 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
