/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_message_cache_construct)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_base_init = 0x8015f4c4;
w3d_cached_message_id = 0x8015f5a0;
w3d_empty_804b06a0 = 0x804b06a0;
w3d_string_assign = 0x8020bd38;
w3d_string_default = 0x803426b8;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_message_cache_construct 0x8015f4cc : { *(.text.w3d_message_cache_construct) }
  .text.w3d_message_cache_equals 0x8015f620 : { *(.text.w3d_message_cache_equals) }
  .text.w3d_message_id_equals_cache 0x8015f65c : { *(.text.w3d_message_id_equals_cache) }
  .text.w3d_text_cache_construct 0x8015f704 : { *(.text.w3d_text_cache_construct) }
  .text.w3d_text_cache_assign 0x8015f74c : { *(.text.w3d_text_cache_assign) }
  .text.w3d_callback_link 0x8015f7e0 : { *(.text.w3d_callback_link) }
  .text.w3d_callback_dispatch 0x8015fc84 : { *(.text.w3d_callback_dispatch) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
