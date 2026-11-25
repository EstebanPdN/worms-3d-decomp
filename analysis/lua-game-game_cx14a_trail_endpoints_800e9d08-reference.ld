/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx14a_trail_endpoints_800e9d08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
matrix_80343740 = 0x80343740;
resolve_80164fc8 = 0x80164fc8;
segment_80122800 = 0x80122800;
SECTIONS {
  .text.w3d_cx14a_trail_endpoints_800e9d08 0x800e9d08 : { *(.text.w3d_cx14a_trail_endpoints_800e9d08) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
