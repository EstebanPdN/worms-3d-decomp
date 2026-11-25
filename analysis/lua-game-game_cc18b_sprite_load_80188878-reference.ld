/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc18b_sprite_load_80188878)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc18b_descriptor_load_80190538 = 0x80190538;
cc18b_group_name_803a7b9c = 0x803a7b9c;
SECTIONS {
  .text.w3d_cc18b_sprite_load_80188878 0x80188878 : { *(.text.w3d_cc18b_sprite_load_80188878) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
