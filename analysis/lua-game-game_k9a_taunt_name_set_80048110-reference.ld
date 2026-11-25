/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k9a_taunt_name_set_80048110)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800fc2b0 = 0x800fc2b0;
w3d_auto_8015ff5c = 0x8015ff5c;
w3d_fn_80043134 = 0x80043134;
w3d_str_803763c0 = 0x803763c0;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_default = 0x803426b8;
w3d_string_format = 0x8020c510;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_k9a_taunt_name_set_80048110 0x80048110 : { *(.text.w3d_k9a_taunt_name_set_80048110) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
