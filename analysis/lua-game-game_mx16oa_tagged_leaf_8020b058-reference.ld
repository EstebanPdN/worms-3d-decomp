/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__16Mx16oaTaggedLeaf)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_vt.16Mx16oaTaggedLeaf = 0x804194a0;
_vt.16Mx16oaTaggedRoot = 0x804181c0;
SECTIONS {
  .text.__16Mx16oaTaggedLeaf 0x8020b058 : { *(.text.__16Mx16oaTaggedLeaf) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
