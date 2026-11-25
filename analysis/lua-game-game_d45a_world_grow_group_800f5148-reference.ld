/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d45a_world_grow_group_800f5148)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
adjust_800f6c54 = 0x800f6c54;
alloc_80212fd4 = 0x80212fd4;
find_800f58f0 = 0x800f58f0;
layer_800f55e8 = 0x800f55e8;
memcpy = 0x802eee50;
need_8038c588 = 0x8038c588;
place_800f5c1c = 0x800f5c1c;
rand_800f2cec = 0x800f2cec;
rare_8038c5e4 = 0x8038c5e4;
release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_d45a_world_grow_group_800f5148 0x800f5148 : { *(.text.w3d_d45a_world_grow_group_800f5148) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
