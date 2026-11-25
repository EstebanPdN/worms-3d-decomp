/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_c34_reset_progress_802ba0cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_803d8118 = 0x803d8118;
w3d_f32_803d811c = 0x803d811c;
w3d_refresh_802b929c = 0x802b929c;
SECTIONS {
  .text.tsonnet_c34_reset_progress_802ba0cc 0x802ba0cc : { *(.text.tsonnet_c34_reset_progress_802ba0cc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
