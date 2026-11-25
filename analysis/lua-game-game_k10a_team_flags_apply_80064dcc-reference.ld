/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_team_flags_apply_80064dcc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
atoi = 0x802ed89c;
w3d_auto_80178df0 = 0x80178df0;
w3d_empty_8034357c = 0x8034357c;
w3d_handle_set_name = 0x8015adf4;
w3d_s20_store_byte_value_80173f88 = 0x80173f88;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_k10a_team_flags_apply_80064dcc 0x80064dcc : { *(.text.w3d_k10a_team_flags_apply_80064dcc) }
  .rodata 0x80379de4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
