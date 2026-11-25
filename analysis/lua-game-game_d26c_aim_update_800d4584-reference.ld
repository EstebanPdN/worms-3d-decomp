/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_aim_update_800d4584)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
desc_801797b4 = 0x801797b4;
ease_800d4734 = 0x800d4734;
ease_800d47f0 = 0x800d47f0;
empty_80341584 = 0x80341584;
zero_80388d04 = 0x80388d04;
SECTIONS {
  .text.d26c_aim_update_800d4584 0x800d4584 : { *(.text.d26c_aim_update_800d4584) }
  .rodata 0x80388d08 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
