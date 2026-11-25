/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f2b_vector_probe_800d066c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
probe_800cffa0 = 0x800cffa0;
SECTIONS {
  .text.f2b_vector_probe_800d066c 0x800d066c : { *(.text.f2b_vector_probe_800d066c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
