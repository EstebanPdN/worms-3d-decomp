/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f4b_offset_position_8004eb34)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
one_80377880 = 0x80377880;
rise_80377884 = 0x80377884;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.f4b_offset_position_8004eb34 0x8004eb34 : { *(.text.f4b_offset_position_8004eb34) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
