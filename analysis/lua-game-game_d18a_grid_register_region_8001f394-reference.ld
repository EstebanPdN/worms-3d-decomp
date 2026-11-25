/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d18a_grid_register_region_8001f394)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d18a_allocate_8001523c = 0x8001523c;
d18a_allocate_80212fd4 = 0x80212fd4;
d18a_copy_802eee50 = 0x802eee50;
d18a_grid_find_region_8001f30c = 0x8001f30c;
d18a_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_d18a_grid_register_region_8001f394 0x8001f394 : { *(.text.w3d_d18a_grid_register_region_8001f394) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
