/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k5b_string_array_resized_801eec98)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_string_base_init = 0x8020c5c0;
w3d_string_default = 0x803426b8;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.w3d_k5b_string_array_resized_801eec98 0x801eec98 : { *(.text.w3d_k5b_string_array_resized_801eec98) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
