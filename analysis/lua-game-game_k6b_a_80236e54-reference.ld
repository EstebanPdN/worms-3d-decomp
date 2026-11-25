/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_label_record_construct_80236e54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8041a7c0 = 0x8041a7c0;
lbl_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_tagged_construct_801ea0ec = 0x801ea0ec;
SECTIONS {
  .text.w3d_k6b_label_record_construct_80236e54 0x80236e54 : { *(.text.w3d_k6b_label_record_construct_80236e54) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
