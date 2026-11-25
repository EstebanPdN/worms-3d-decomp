/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_artillery_mode_800154e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s8_index_query_800fc6dc = 0x800fc6dc;
w3d_auto_800fc230 = 0x800fc230;
SECTIONS {
  .text.s19_artillery_mode_800154e0 0x800154e0 : { *(.text.s19_artillery_mode_800154e0) }
  .rodata 0x8036a59c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
