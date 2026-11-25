/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f1b_integrate_velocity_80146aa4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
f1b_damp_803a0fc8 = 0x803a0fc8;
f1b_ease_803a0fd0 = 0x803a0fd0;
f1b_step_803a0fc0 = 0x803a0fc0;
f1b_target_803a0fcc = 0x803a0fcc;
f1b_threshold_803a0fc4 = 0x803a0fc4;
SECTIONS {
  .text.f1b_integrate_velocity_80146aa4 0x80146aa4 : { *(.text.f1b_integrate_velocity_80146aa4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
