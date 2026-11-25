/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc24a_planner_decay_entries_800169e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc24a_copy_802eee50 = 0x802eee50;
cc24a_destroy_80015d18 = 0x80015d18;
SECTIONS {
  .text.cc24a_planner_decay_entries_800169e0 0x800169e0 : { *(.text.cc24a_planner_decay_entries_800169e0) }
  .rodata 0x8036a69c : { *(.rodata) }
  .sdata 0x804aa700 (NOLOAD) : {
    . = 0x0; cc24a_entries_804aa700 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
