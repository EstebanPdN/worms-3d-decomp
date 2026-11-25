/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_motion_step_800d3160)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_motion_adjust_800d4584 = 0x800d4584;
w3d_motion_apply_800d3208 = 0x800d3208;
w3d_motion_direction_800d4d64 = 0x800d4d64;
w3d_motion_finish_800d40f4 = 0x800d40f4;
w3d_motion_test_8015ac04 = 0x8015ac04;
SECTIONS {
  .text.w3d_motion_step_800d3160 0x800d3160 : { *(.text.w3d_motion_step_800d3160) }
  .text.w3d_motion_test_pair_800d4cec 0x800d4cec : { *(.text.w3d_motion_test_pair_800d4cec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
