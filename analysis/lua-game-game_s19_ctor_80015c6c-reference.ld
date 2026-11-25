/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_marker_ctor_80015c6c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80015588 = 0x80015588;
SECTIONS {
  .text.s19_marker_ctor_80015c6c 0x80015c6c : { *(.text.s19_marker_ctor_80015c6c) }
  .rodata 0x8036a648 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
