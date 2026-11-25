/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_shape_check_801d6644)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_k8b_log_801d6000 = 0x801d6000;
w3d_s20_dispatch_two_targets_801a3adc = 0x801a3adc;
SECTIONS {
  .text.w3d_k8b_shape_check_801d6644 0x801d6644 : { *(.text.w3d_k8b_shape_check_801d6644) }
  .rodata 0x803af4f4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
