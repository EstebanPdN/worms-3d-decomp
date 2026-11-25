/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__static_initialization_and_destruction_0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.__static_initialization_and_destruction_0 0x80141b14 : { *(.text.__static_initialization_and_destruction_0) }
  .ctors 0x8035f724 : { *(.ctors) }
  .rodata 0x803a0490 : { *(.rodata) }
  .bss 0x80453030 : { *(.bss) }
  .sbss 0x804afa48 : { *(.sbss) }
  .sdata 0x804ab3c8 (NOLOAD) : {
    . = 0x0; lbl_804ab3c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
