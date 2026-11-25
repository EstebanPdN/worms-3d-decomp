/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25d_worm_stuck_step_8014c4f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
constrain_8014b40c = 0x8014b40c;
context_80165254 = 0x80165254;
resolve_8014157c = 0x8014157c;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d25d_worm_stuck_step_8014c4f4 0x8014c4f4 : { *(.text.d25d_worm_stuck_step_8014c4f4) }
  .rodata 0x803a14a4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
