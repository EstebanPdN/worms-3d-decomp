/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_active_worm_apply_800217d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s8_index_query_800fc6dc = 0x800fc6dc;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_string_active_worm_index_8036c014 = 0x8036c014;
SECTIONS {
  .text.k4a_active_worm_apply_800217d0 0x800217d0 : { *(.text.k4a_active_worm_apply_800217d0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
