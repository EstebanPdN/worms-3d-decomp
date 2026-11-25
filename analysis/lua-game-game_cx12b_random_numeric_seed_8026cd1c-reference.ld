/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12b_random_numeric_seed_8026cd1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
assign_8020bd38 = 0x8020bd38;
parse_8026c8a8 = 0x8026c8a8;
random_80162ba8 = 0x80162ba8;
spaces_803cbc84 = 0x803cbc84;
truncate_8020c3a0 = 0x8020c3a0;
write_8020be94 = 0x8020be94;
SECTIONS {
  .text.w3d_cx12b_random_numeric_seed_8026cd1c 0x8026cd1c : { *(.text.w3d_cx12b_random_numeric_seed_8026cd1c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
