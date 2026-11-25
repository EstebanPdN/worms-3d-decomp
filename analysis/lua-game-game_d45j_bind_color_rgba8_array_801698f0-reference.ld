/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(bind_color_rgba8_array_801698f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
DCFlushRange = 0x802fa988;
GXSetArray = 0x80307d88;
SECTIONS {
  .text.bind_color_rgba8_array_801698f0 0x801698f0 : { *(.text.bind_color_rgba8_array_801698f0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
