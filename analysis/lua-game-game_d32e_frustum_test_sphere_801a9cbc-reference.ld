/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32e_frustum_test_sphere_801a9cbc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_d24e_transform_sphere_801f5214 = 0x801f5214;
SECTIONS {
  .text.w3d_d32e_frustum_test_sphere_801a9cbc 0x801a9cbc : { *(.text.w3d_d32e_frustum_test_sphere_801a9cbc) }
  .rodata 0x803aa0f0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
