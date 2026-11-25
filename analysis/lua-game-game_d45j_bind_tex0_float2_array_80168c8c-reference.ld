/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(bind_tex0_float2_array_80168c8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
DCFlushRange = 0x802fa988;
GXSetArray = 0x80307d88;
SECTIONS {
  .text.bind_tex0_float2_array_80168c8c 0x80168c8c : { *(.text.bind_tex0_float2_array_80168c8c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
