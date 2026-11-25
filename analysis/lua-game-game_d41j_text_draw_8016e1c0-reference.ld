/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41j_text_draw_8016e1c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
append_8016e908 = 0x8016e908;
glyph_8016e09c = 0x8016e09c;
next_char_802fd9c4 = 0x802fd9c4;
quad_8016dfcc = 0x8016dfcc;
SECTIONS {
  .text.w3d_d41j_text_draw_8016e1c0 0x8016e1c0 : { *(.text.w3d_d41j_text_draw_8016e1c0) }
  .rodata 0x803a6358 : { *(.rodata) }
  .sdata 0x804b1888 (NOLOAD) : {
    . = 0x0; gx_804b1888 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
