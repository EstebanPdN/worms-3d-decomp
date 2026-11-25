/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d43a_commentary_wrap_text_80043134)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
w3d_commentary_append_80042d04 = 0x80042d04;
w3d_empty_string_804b06a0 = 0x804b06a0;
w3d_string_append_8020bf2c = 0x8020bf2c;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_header_80341884 = 0x80341884;
w3d_string_init_8020c5c0 = 0x8020c5c0;
w3d_string_prefix_8020c048 = 0x8020c048;
w3d_string_release_80341588 = 0x80341588;
w3d_string_release_header_8020bb2c = 0x8020bb2c;
w3d_string_suffix_8020c0fc = 0x8020c0fc;
SECTIONS {
  .text.w3d_d43a_commentary_wrap_text_80043134 0x80043134 : { *(.text.w3d_d43a_commentary_wrap_text_80043134) }
  .rodata 0x80374dd8 : { *(.rodata) }
  .sdata 0x804aa978 (NOLOAD) : {
    . = 0x0; w3d_time_804aa978 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
