/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_iface_add_801d4544)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_k5b_iface_array_field_append_801ef174 = 0x801ef174;
w3d_k5b_iface_array_field_set_801ef2ec = 0x801ef2ec;
SECTIONS {
  .text.w3d_k8b_iface_add_801d4544 0x801d4544 : { *(.text.w3d_k8b_iface_add_801d4544) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
