/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(e14b_string_compact_800c4a7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_memcpy_802eee50 = 0x802eee50;
w3d_string_assign = 0x8020bd38;
SECTIONS {
  .text.e14b_string_compact_800c4a7c 0x800c4a7c : { *(.text.e14b_string_compact_800c4a7c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
