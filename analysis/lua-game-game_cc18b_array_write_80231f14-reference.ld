/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc18b_array_write_80231f14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_array_reserve_801ef048 = 0x801ef048;
SECTIONS {
  .text.w3d_cc18b_array_write_80231f14 0x80231f14 : { *(.text.w3d_cc18b_array_write_80231f14) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
