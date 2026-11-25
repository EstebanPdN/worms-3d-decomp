/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d10a_acquire_slot_8017180c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d10a_add_count_80190438 = 0x80190438;
d10a_kind_counts_804a89d8 = 0x804a89d8;
d10a_select_80172088 = 0x80172088;
SECTIONS {
  .text.d10a_acquire_slot_8017180c 0x8017180c : { *(.text.d10a_acquire_slot_8017180c) }
  .sdata 0x804b189c (NOLOAD) : {
    . = 0x0; d10a_slots_804b189c = .;
    . = 0x4; d10a_free_indices_804b18a0 = .;
    . = 0xa; d10a_free_count_804b18a6 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
