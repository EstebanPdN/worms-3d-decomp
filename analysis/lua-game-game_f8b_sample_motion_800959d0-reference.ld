/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f8b_sample_motion_800959d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
clamp_800949a8 = 0x800949a8;
middle_8037ebc0 = 0x8037ebc0;
one_8037ebb8 = 0x8037ebb8;
side_8037ebbc = 0x8037ebbc;
zero_8037eba8 = 0x8037eba8;
SECTIONS {
  .text.f8b_sample_motion_800959d0 0x800959d0 : { *(.text.f8b_sample_motion_800959d0) }
  .rodata 0x8037ebb0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
