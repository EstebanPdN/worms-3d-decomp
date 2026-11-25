/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_named_range_construct_80239d60)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8041af40 = 0x8041af40;
lbl_804b06a0 = 0x804b06a0;
w3d_auto_80238d88 = 0x80238d88;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.w3d_k6b_named_range_construct_80239d60 0x80239d60 : { *(.text.w3d_k6b_named_range_construct_80239d60) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
