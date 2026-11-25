/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31h_free_camera_input_800a8d00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
blend_800a93fc = 0x800a93fc;
cosf_802e86d4 = 0x802e86d4;
lbl_80439590 = 0x80439590;
limit_800a9b60 = 0x800a9b60;
sinf_802e88ac = 0x802e88ac;
sqrt_802e82c0 = 0x802e82c0;
value_80178df0 = 0x80178df0;
vector_80178ec4 = 0x80178ec4;
SECTIONS {
  .text.d31h_free_camera_input_800a8d00 0x800a8d00 : { *(.text.d31h_free_camera_input_800a8d00) }
  .rodata 0x803818f8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
