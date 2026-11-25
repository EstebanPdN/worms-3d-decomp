/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f8b_launch_vector_8000d374)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
center_8041d3a0 = 0x8041d3a0;
speed_80369e64 = 0x80369e64;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.f8b_launch_vector_8000d374 0x8000d374 : { *(.text.f8b_launch_vector_8000d374) }
  .rodata 0x80369e5c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
