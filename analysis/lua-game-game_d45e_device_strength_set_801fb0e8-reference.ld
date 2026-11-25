/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d45e_device_strength_set_801fb0e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
kByteScale_803b1c0c = 0x803b1c0c;
SECTIONS {
  .text.w3d_d45e_device_strength_set_801fb0e8 0x801fb0e8 : { *(.text.w3d_d45e_device_strength_set_801fb0e8) }
  .rodata 0x803b1c10 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
