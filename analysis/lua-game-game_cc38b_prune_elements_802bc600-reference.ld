/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc38b_prune_elements_802bc600)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc38b_copy_802eee50 = 0x802eee50;
cc38b_destroy_802bcfb4 = 0x802bcfb4;
SECTIONS {
  .text.cc38b_prune_elements_802bc600 0x802bc600 : { *(.text.cc38b_prune_elements_802bc600) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
