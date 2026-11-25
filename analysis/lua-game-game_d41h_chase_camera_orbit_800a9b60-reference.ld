/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d41h_chase_camera_orbit_800a9b60)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
euler_matrix_801a3eb0 = 0x801a3eb0;
lbl_80439590 = 0x80439590;
target_range_80178df0 = 0x80178df0;
SECTIONS {
  .text.d41h_chase_camera_orbit_800a9b60 0x800a9b60 : { *(.text.d41h_chase_camera_orbit_800a9b60) }
  .rodata 0x8038199c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
