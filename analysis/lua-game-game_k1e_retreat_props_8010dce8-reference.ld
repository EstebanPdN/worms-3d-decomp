/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k1e_retreat_reset_8010dce8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s8_property_write_800fc3b0 = 0x800fc3b0;
w3d_constructor_lookup_name = 0x800fc1b0;
SECTIONS {
  .text.w3d_k1e_retreat_reset_8010dce8 0x8010dce8 : { *(.text.w3d_k1e_retreat_reset_8010dce8) }
  .rodata 0x80399f90 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
