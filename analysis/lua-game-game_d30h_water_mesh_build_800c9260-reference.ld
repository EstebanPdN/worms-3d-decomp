/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30h_water_mesh_build_800c9260)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_array_ref_lock_801ef048 = 0x801ef048;
SECTIONS {
  .text.d30h_water_mesh_build_800c9260 0x800c9260 : { *(.text.d30h_water_mesh_build_800c9260) }
  .rodata 0x80387be8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
