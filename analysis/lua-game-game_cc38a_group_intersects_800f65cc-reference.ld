/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc38a_group_intersects_800f65cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc38a_intersects_800c59cc = 0x800c59cc;
SECTIONS {
  .text.cc38a_group_intersects_800f65cc 0x800f65cc : { *(.text.cc38a_group_intersects_800f65cc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
