/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_target_cache_context_80064d20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80064384 = 0x80064384;
FUN_8018d35c = 0x8018d35c;
s8_indexed_property_800fd3e4 = 0x800fd3e4;
w3d_empty_80343580 = 0x80343580;
w3d_engine_get_context = 0x80165254;
SECTIONS {
  .text.k4a_target_cache_context_80064d20 0x80064d20 : { *(.text.k4a_target_cache_context_80064d20) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
