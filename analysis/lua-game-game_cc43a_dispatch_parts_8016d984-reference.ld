/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc43a_dispatch_parts_8016d984)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc43a_draw_part_8016d49c = 0x8016d49c;
SECTIONS {
  .text.cc43a_dispatch_parts_8016d984 0x8016d984 : { *(.text.cc43a_dispatch_parts_8016d984) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
