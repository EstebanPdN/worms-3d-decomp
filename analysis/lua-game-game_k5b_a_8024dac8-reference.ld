/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k5b_labelled_frame_construct_8024dac8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8041b7f8 = 0x8041b7f8;
lbl_804b06a0 = 0x804b06a0;
w3d_k4b_named_color_construct_801b4bcc = 0x801b4bcc;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.w3d_k5b_labelled_frame_construct_8024dac8 0x8024dac8 : { *(.text.w3d_k5b_labelled_frame_construct_8024dac8) }
  .rodata 0x803c5110 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
