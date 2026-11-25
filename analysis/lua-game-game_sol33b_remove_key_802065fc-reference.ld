/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol33b_remove_key_802065fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
erase_keys_80210dd8 = 0x80210dd8;
find_int_8035c170 = 0x8035c170;
sol33b_finish_8020c5c4 = 0x8020c5c4;
sol33b_release_80341588 = 0x80341588;
sol33b_release_header_8020bb2c = 0x8020bb2c;
SECTIONS {
  .text.sol33b_remove_key_802065fc 0x802065fc : { *(.text.sol33b_remove_key_802065fc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
