/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g3c_flush_pending_802171ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
callbacks_80400768 = 0x80400768;
SECTIONS {
  .text.g3c_flush_pending_802171ec 0x802171ec : { *(.text.g3c_flush_pending_802171ec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
