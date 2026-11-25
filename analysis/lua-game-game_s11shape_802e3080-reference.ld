/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_constant_802e3080)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_802e3178 = 0x802e3178;
w3d_sinit_802e3088 = 0x802e3088;
SECTIONS {
  .text.w3d_constant_802e3080 0x802e3080 : { *(.text.w3d_constant_802e3080) }
  .text.w3d_static_init_802e30e4 0x802e30e4 : { *(.text.w3d_static_init_802e30e4) }
  .text.w3d_static_init_802e31c0 0x802e31c0 : { *(.text.w3d_static_init_802e31c0) }
  .text.w3d_empty_802e3854 0x802e3854 : { *(.text.w3d_empty_802e3854) }
  .text.w3d_empty_802e4cd8 0x802e4cd8 : { *(.text.w3d_empty_802e4cd8) }
  .text.w3d_empty_802e4ce0 0x802e4ce0 : { *(.text.w3d_empty_802e4ce0) }
  .text.w3d_empty_802e4ce8 0x802e4ce8 : { *(.text.w3d_empty_802e4ce8) }
  .text.w3d_empty_802e4cf0 0x802e4cf0 : { *(.text.w3d_empty_802e4cf0) }
  .text.w3d_empty_802e4cf8 0x802e4cf8 : { *(.text.w3d_empty_802e4cf8) }
  .text.w3d_empty_802e4d00 0x802e4d00 : { *(.text.w3d_empty_802e4d00) }
  .text.w3d_empty_802e4d08 0x802e4d08 : { *(.text.w3d_empty_802e4d08) }
  .text.w3d_empty_802e5288 0x802e5288 : { *(.text.w3d_empty_802e5288) }
  .text.w3d_empty_802e528c 0x802e528c : { *(.text.w3d_empty_802e528c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
