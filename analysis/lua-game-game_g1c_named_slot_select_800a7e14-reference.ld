/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g1c_named_slot_select_800a7e14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
compare_802ef234 = 0x802ef234;
empty_803814dc = 0x803814dc;
find_800a7da4 = 0x800a7da4;
seek_800a7ee4 = 0x800a7ee4;
SECTIONS {
  .text.g1c_named_slot_select_800a7e14 0x800a7e14 : { *(.text.g1c_named_slot_select_800a7e14) }
  .sdata 0x804aac54 (NOLOAD) : {
    . = 0x0; owner_804aac54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
