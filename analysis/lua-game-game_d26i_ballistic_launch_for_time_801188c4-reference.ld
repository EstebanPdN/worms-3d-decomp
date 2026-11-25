/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26i_ballistic_launch_for_time_801188c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_copy12_800d7788 = 0x800d7788;
SECTIONS {
  .text.d26i_ballistic_launch_for_time_801188c4 0x801188c4 : { *(.text.d26i_ballistic_launch_for_time_801188c4) }
  .rodata 0x8039a9c4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
