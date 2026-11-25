/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8c_child_scale_countdown_802c5f4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
one_803d8d0c = 0x803d8d0c;
step_803d8d08 = 0x803d8d08;
SECTIONS {
  .text.w3d_k8c_child_scale_countdown_802c5f4c 0x802c5f4c : { *(.text.w3d_k8c_child_scale_countdown_802c5f4c) }
  .rodata 0x803d8d00 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
