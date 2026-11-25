/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_named_construct_801c90c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_804163c0 = 0x804163c0;
lbl_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_tagged_construct_801ea0ec = 0x801ea0ec;
SECTIONS {
  .text.w3d_k4b_named_construct_801c90c0 0x801c90c0 : { *(.text.w3d_k4b_named_construct_801c90c0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
