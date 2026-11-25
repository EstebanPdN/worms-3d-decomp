/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol31b_remove_current_v3_80155ba4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cast_80342a78 = 0x80342a78;
current_index_80178d1c = 0x80178d1c;
memcpy = 0x802eee50;
notify_empty_801565e4 = 0x801565e4;
team_query_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.sol31b_remove_current_v3_80155ba4 0x80155ba4 : { *(.text.sol31b_remove_current_v3_80155ba4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
