/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k2a_marker_push_800f2810)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_8038c4a4 = 0x8038c4a4;
SECTIONS {
  .text.k2a_marker_push_800f2810 0x800f2810 : { *(.text.k2a_marker_push_800f2810) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
