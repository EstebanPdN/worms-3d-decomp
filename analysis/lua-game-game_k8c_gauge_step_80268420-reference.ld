/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8c_gauge_step_80268420)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802683b8 = 0x802683b8;
w3d_f32_803cb74c = 0x803cb74c;
w3d_f32_803cb750 = 0x803cb750;
w3d_f32_803cb754 = 0x803cb754;
w3d_f32_803cb758 = 0x803cb758;
w3d_f32_803cb75c = 0x803cb75c;
w3d_f32_803cb760 = 0x803cb760;
SECTIONS {
  .text.w3d_k8c_gauge_step_80268420 0x80268420 : { *(.text.w3d_k8c_gauge_step_80268420) }
  .text.w3d_k8c_gauge_step_down_802684c4 0x802684c4 : { *(.text.w3d_k8c_gauge_step_down_802684c4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
