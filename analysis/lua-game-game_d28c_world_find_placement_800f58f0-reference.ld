/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28c_world_find_placement_800f58f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
adjust_800f6c54 = 0x800f6c54;
all_ge_800f5894 = 0x800f5894;
mask_test_800f58dc = 0x800f58dc;
need_8038c588 = 0x8038c588;
place_test_800f68bc = 0x800f68bc;
SECTIONS {
  .text.d28c_world_find_placement_800f58f0 0x800f58f0 : { *(.text.d28c_world_find_placement_800f58f0) }
  .sdata 0x804af0c8 (NOLOAD) : {
    . = 0x0; count_804af0c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
