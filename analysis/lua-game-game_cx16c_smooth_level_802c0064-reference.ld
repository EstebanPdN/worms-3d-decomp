/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16c_smooth_level_802c0064)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx16c_factor_803d8428 = 0x803d8428;
cx16c_lower_803d8434 = 0x803d8434;
cx16c_one_803d842c = 0x803d842c;
cx16c_refresh_802bfc64 = 0x802bfc64;
cx16c_upper_803d8430 = 0x803d8430;
SECTIONS {
  .text.w3d_cx16c_smooth_level_802c0064 0x802c0064 : { *(.text.w3d_cx16c_smooth_level_802c0064) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
