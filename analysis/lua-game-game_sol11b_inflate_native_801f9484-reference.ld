/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol11b_inflate_native_801f9484)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
inflate = 0x802c8468;
inflateEnd = 0x802c8280;
SECTIONS {
  .text.sol11b_inflate_native_801f9484 0x801f9484 : { *(.text.sol11b_inflate_native_801f9484) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
