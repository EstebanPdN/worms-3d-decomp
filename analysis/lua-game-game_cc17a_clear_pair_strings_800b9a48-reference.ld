/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17a_clear_pair_strings_800b9a48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
copy_802eee50 = 0x802eee50;
destroy_800b916c = 0x800b916c;
SECTIONS {
  .text.w3d_cc17a_clear_pair_strings_800b9a48 0x800b9a48 : { *(.text.w3d_cc17a_clear_pair_strings_800b9a48) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
