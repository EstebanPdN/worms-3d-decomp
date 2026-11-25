/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k5b_text_array_set_count_801eef90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_804b06a0 = 0x804b06a0;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_k5b_text_array_set_count_801eef90 0x801eef90 : { *(.text.w3d_k5b_text_array_set_count_801eef90) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
