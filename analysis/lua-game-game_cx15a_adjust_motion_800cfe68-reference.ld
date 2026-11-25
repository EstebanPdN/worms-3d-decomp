/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx15a_adjust_motion_800cfe68)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
correct_800d0710 = 0x800d0710;
dispatch_800d0c88 = 0x800d0c88;
finish_800d13d0 = 0x800d13d0;
prepare_800d1130 = 0x800d1130;
solve_800d0108 = 0x800d0108;
SECTIONS {
  .text.w3d_cx15a_adjust_motion_800cfe68 0x800cfe68 : { *(.text.w3d_cx15a_adjust_motion_800cfe68) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
