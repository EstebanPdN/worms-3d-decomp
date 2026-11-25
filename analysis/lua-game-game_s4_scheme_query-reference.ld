/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_scheme_is_user_defined)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcmp = 0x802ef234;
w3d_auto_801797b4 = 0x801797b4;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80341584 = 0x80341584;
w3d_lookup_text_800fc2b0 = 0x800fc2b0;
w3d_str_803d0174 = 0x803d0174;
w3d_str_803d04a4 = 0x803d04a4;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_default = 0x803426b8;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_s4_scheme_is_user_defined 0x802931d4 : { *(.text.w3d_s4_scheme_is_user_defined) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
