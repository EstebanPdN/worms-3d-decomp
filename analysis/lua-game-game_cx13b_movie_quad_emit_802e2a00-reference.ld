/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx13b_movie_quad_emit_802e2a00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
begin_803089c8 = 0x803089c8;
bind_8030a21c = 0x8030a21c;
fifo_cc008000 = 0xcc008000;
SECTIONS {
  .text.w3d_cx13b_movie_quad_emit_802e2a00 0x802e2a00 : { *(.text.w3d_cx13b_movie_quad_emit_802e2a00) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
