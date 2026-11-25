/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25b_girder_preview_80093518)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
f8b_sample_motion_800959d0 = 0x800959d0;
s19_handle_cast_query_80096564 = 0x80096564;
w3d_empty_80343584 = 0x80343584;
w3d_handle_colour_801266ac = 0x801266ac;
w3d_handle_position_801265ec = 0x801265ec;
w3d_lookup_handle_80164fc8 = 0x80164fc8;
w3d_set_tint_80182178 = 0x80182178;
SECTIONS {
  .text.w3d_d25b_girder_preview_80093518 0x80093518 : { *(.text.w3d_d25b_girder_preview_80093518) }
  .rodata 0x8037e9d4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
