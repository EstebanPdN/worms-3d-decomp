/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28h_sphere_hits_voxels_800b1410)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cell_center_800b41c4 = 0x800b41c4;
grid_test_8002c73c = 0x8002c73c;
lock_801ef048 = 0x801ef048;
SECTIONS {
  .text.d28h_sphere_hits_voxels_800b1410 0x800b1410 : { *(.text.d28h_sphere_hits_voxels_800b1410) }
  .rodata 0x80382400 : { *(.rodata) }
  .sdata 0x804b17e0 (NOLOAD) : {
    . = 0x0; g_game_804b17e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
