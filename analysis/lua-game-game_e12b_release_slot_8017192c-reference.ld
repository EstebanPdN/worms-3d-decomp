/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(e12b_release_slot_8017192c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
e12b_bitset_801720c0 = 0x801720c0;
e12b_kind_counts_804a89d8 = 0x804a89d8;
e12b_release_count_80190458 = 0x80190458;
e12b_select_80172088 = 0x80172088;
SECTIONS {
  .text.e12b_release_slot_8017192c 0x8017192c : { *(.text.e12b_release_slot_8017192c) }
  .sdata 0x804b18a0 (NOLOAD) : {
    . = 0x0; e12b_free_indices_804b18a0 = .;
    . = 0x6; e12b_free_count_804b18a6 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
