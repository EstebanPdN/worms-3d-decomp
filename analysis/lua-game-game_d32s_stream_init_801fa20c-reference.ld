/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(init__10D32sStreamii)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_M_fill_insert__Q24_STLt6vector2ZUcZQ24_STLt9allocator1ZUcPUcUiRCUc = 0x80359d9c;
_M_fill_insert__Q24_STLt6vector2ZfZQ24_STLt9allocator1ZfPfUiRCf = 0x80359f84;
fn_80301e04 = 0x80301e04;
lbl_8045e824 = 0x8045e824;
SECTIONS {
  .text.init__10D32sStreamii 0x801fa20c : { *(.text.init__10D32sStreamii) }
  .rodata 0x803b1a98 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
