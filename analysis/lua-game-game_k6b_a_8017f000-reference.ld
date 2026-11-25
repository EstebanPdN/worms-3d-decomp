/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_entry_assign_8017f000)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_string_assign = 0x8020bd38;
SECTIONS {
  .text.w3d_k6b_entry_assign_8017f000 0x8017f000 : { *(.text.w3d_k6b_entry_assign_8017f000) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
