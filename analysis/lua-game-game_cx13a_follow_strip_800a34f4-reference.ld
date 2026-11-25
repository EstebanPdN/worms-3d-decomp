/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx13a_follow_strip_800a34f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cast_8034380c = 0x8034380c;
read_80178df0 = 0x80178df0;
read_80178ec4 = 0x80178ec4;
vertices_8018963c = 0x8018963c;
SECTIONS {
  .text.w3d_cx13a_follow_strip_800a34f4 0x800a34f4 : { *(.text.w3d_cx13a_follow_strip_800a34f4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
