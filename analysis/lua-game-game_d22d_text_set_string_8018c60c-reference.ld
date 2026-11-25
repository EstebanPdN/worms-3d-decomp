/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d22d_text_set_string_8018c60c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memcpy = 0x802eee50;
memmove = 0x802eeef4;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
w3d_k1d_lookup_entry_8018b260 = 0x8018b260;
w3d_text_layout_8018ca30 = 0x8018ca30;
w3d_view_8034435c = 0x8034435c;
SECTIONS {
  .text.w3d_d22d_text_set_string_8018c60c 0x8018c60c : { *(.text.w3d_d22d_text_set_string_8018c60c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
