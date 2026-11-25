/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(bind_normal_short3_array_80169704)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
DCFlushRange = 0x802fa988;
GXSetArray = 0x80307d88;
SECTIONS {
  .text.bind_normal_short3_array_80169704 0x80169704 : { *(.text.bind_normal_short3_array_80169704) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
