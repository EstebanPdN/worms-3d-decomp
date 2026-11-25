/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__14Mx21obFeSliderUs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__14Mx21obFeButtonUs = 0x8021fd28;
_vt.14Mx21obFeSlider = 0x8041a5a0;
w3d_empty_string_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_from_text = 0x8020bb54;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.__14Mx21obFeSliderUs 0x80220200 : { *(.text.__14Mx21obFeSliderUs) }
  .rodata 0x803b6408 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
