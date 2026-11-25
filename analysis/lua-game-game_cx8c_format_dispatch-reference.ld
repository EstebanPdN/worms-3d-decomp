/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx8c_format_dispatch_802f06c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx8c_format_float_802f07a0 = 0x802f07a0;
cx8c_format_integer_802f1cf4 = 0x802f1cf4;
SECTIONS {
  .text.w3d_cx8c_format_dispatch_802f06c8 0x802f06c8 : { *(.text.w3d_cx8c_format_dispatch_802f06c8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
