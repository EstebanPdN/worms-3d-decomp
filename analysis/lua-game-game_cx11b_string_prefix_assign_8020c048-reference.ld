/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11b_string_prefix_assign_8020c048)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_8020bc88 = 0x8020bc88;
copy_802eee50 = 0x802eee50;
release_8020bb2c = 0x8020bb2c;
SECTIONS {
  .text.w3d_cx11b_string_prefix_assign_8020c048 0x8020c048 : { *(.text.w3d_cx11b_string_prefix_assign_8020c048) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
