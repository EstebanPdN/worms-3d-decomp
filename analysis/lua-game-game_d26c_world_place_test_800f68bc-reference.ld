/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_world_place_test_800f68bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cleanup_800f6ca0 = 0x800f6ca0;
frustum_800f6798 = 0x800f6798;
make_800f55e8 = 0x800f55e8;
overlap_800f65cc = 0x800f65cc;
place_800f5c1c = 0x800f5c1c;
plane_800f66ac = 0x800f66ac;
touch_800f6760 = 0x800f6760;
SECTIONS {
  .text.d26c_world_place_test_800f68bc 0x800f68bc : { *(.text.d26c_world_place_test_800f68bc) }
  .rodata 0x8038c584 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
