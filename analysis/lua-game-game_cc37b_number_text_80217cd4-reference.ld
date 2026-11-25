/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc37b_number_text_80217cd4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc37b_hex_digits_803b3800 = 0x803b3800;
cc37b_scratch_suffix_804641b0 = 0x804641b0;
SECTIONS {
  .text.w3d_cc37b_number_text_80217cd4 0x80217cd4 : { *(.text.w3d_cc37b_number_text_80217cd4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
