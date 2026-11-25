/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26d_camera_basis_8015a6f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d26d_camera_basis_8015a6f0 0x8015a6f0 : { *(.text.d26d_camera_basis_8015a6f0) }
  .rodata 0x803a4228 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
