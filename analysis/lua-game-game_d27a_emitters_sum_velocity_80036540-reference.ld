/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27a_emitters_sum_velocity_80036540)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
f9b_random_decay_80036b08 = 0x80036b08;
w3d_auto_80036c8c = 0x80036c8c;
SECTIONS {
  .text.w3d_d27a_emitters_sum_velocity_80036540 0x80036540 : { *(.text.w3d_d27a_emitters_sum_velocity_80036540) }
  .rodata 0x80373ca8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
