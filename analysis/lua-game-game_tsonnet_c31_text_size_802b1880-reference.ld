/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_c31_text_size_802b1880)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178df0 = 0x80178df0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80342a74 = 0x80342a74;
w3d_f32_803d7a68 = 0x803d7a68;
w3d_str_803d7a54 = 0x803d7a54;
SECTIONS {
  .text.tsonnet_c31_text_size_802b1880 0x802b1880 : { *(.text.tsonnet_c31_text_size_802b1880) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
