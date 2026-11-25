/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26j_set_from_frame_80173988)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
atan_802e83ec = 0x802e83ec;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d26j_set_from_frame_80173988 0x80173988 : { *(.text.d26j_set_from_frame_80173988) }
  .rodata 0x803a6708 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
