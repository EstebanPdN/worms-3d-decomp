/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35f2_byte_fill_insert_80342ddc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35f2_allocate_8001528c = 0x8001528c;
sol35f2_fill_802eefe0 = 0x802eefe0;
sol35f2_free_800152ac = 0x800152ac;
sol35f2_move_802eeef4 = 0x802eeef4;
SECTIONS {
  .text.sol35f2_byte_fill_insert_80342ddc 0x80342ddc : { *(.text.sol35f2_byte_fill_insert_80342ddc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
