/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k2a_chat_colour_lookup_8003a028)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800fc370 = 0x800fc370;
w3d_str_803740a0 = 0x803740a0;
w3d_str_803740b4 = 0x803740b4;
w3d_str_803740cc = 0x803740cc;
w3d_str_803740e4 = 0x803740e4;
SECTIONS {
  .text.k2a_chat_colour_lookup_8003a028 0x8003a028 : { *(.text.k2a_chat_colour_lookup_8003a028) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
