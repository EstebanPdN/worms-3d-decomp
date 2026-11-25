/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g4b_remove_flagged_entry_801dc530)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801de10c = 0x801de10c;
fn_80210dd8 = 0x80210dd8;
SECTIONS {
  .text.g4b_remove_flagged_entry_801dc530 0x801dc530 : { *(.text.g4b_remove_flagged_entry_801dc530) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
