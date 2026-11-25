/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc43b_clamp_position_802852c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc43b_maximum_804668dc = 0x804668dc;
cc43b_minimum_804668d0 = 0x804668d0;
SECTIONS {
  .text.cc43b_clamp_position_802852c4 0x802852c4 : { *(.text.cc43b_clamp_position_802852c4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
