/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k7b_registry_clear_801acc48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_801f2758 = 0x801f2758;
w3d_auto_80355800 = 0x80355800;
SECTIONS {
  .text.w3d_k7b_registry_clear_801acc48 0x801acc48 : { *(.text.w3d_k7b_registry_clear_801acc48) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
