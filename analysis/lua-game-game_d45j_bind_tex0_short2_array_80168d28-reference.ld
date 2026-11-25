/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(bind_tex0_short2_array_80168d28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
DCFlushRange = 0x802fa988;
GXSetArray = 0x80307d88;
SECTIONS {
  .text.bind_tex0_short2_array_80168d28 0x80168d28 : { *(.text.bind_tex0_short2_array_80168d28) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
