/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12a_clear_ten_handles_800a3e84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
destroy_8015fd1c = 0x8015fd1c;
lookup_80164fc8 = 0x80164fc8;
SECTIONS {
  .text.w3d_cx12a_clear_ten_handles_800a3e84 0x800a3e84 : { *(.text.w3d_cx12a_clear_ten_handles_800a3e84) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
