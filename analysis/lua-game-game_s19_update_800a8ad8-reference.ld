/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_update_or_idle_800a8ad8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800a8b38 = 0x800a8b38;
FUN_800a8d00 = 0x800a8d00;
w3d_service_optional_context_query = 0x8015abcc;
SECTIONS {
  .text.s19_update_or_idle_800a8ad8 0x800a8ad8 : { *(.text.s19_update_or_idle_800a8ad8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
