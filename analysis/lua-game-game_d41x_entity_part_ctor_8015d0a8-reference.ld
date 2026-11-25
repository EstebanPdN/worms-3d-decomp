/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__19EntityPart_8015d0a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
create_80208aac = 0x80208aac;
SECTIONS {
  .text.__19EntityPart_8015d0a8 0x8015d0a8 : { *(.text.__19EntityPart_8015d0a8) }
  .rodata 0x803a4430 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
