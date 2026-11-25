/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_string_replace_all_801099a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__11d24i_String = 0x803426b8;
__11d24i_StringPCc = 0x8020bb54;
d24i_release_header_8020bb2c = 0x8020bb2c;
d24i_string_append_8020bf2c = 0x8020bf2c;
d24i_string_finish_8020c5c4 = 0x8020c5c4;
d24i_string_prefix_8020c048 = 0x8020c048;
d24i_string_release_80341588 = 0x80341588;
strstr = 0x802efd14;
SECTIONS {
  .text.d24i_string_replace_all_801099a4 0x801099a4 : { *(.text.d24i_string_replace_all_801099a4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
