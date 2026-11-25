/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_twinkle_update_80104be0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24i_as_mesh_8034380c = 0x8034380c;
d24i_mesh_colours_80189760 = 0x80189760;
d24i_one_80399824 = 0x80399824;
d24i_random_8015ff5c = 0x8015ff5c;
d24i_rate_80399820 = 0x80399820;
SECTIONS {
  .text.d24i_twinkle_update_80104be0 0x80104be0 : { *(.text.d24i_twinkle_update_80104be0) }
  .rodata 0x80399818 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
