/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8001ecf8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8036B888 = 0x8036b888;
SECTIONS {
  .text.w3d_auto_8001ecf8 0x8001ecf8 : { *(.text.w3d_auto_8001ecf8) }
  .rodata 0x8036b880 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
