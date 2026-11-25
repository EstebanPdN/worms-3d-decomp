/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17d_string_edit_802796d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80271518 = 0x80271518;
w3d_auto_8027a98c = 0x8027a98c;
w3d_s21_state_dispatch_8027ae00 = 0x8027ae00;
w3d_s21_vector_get_801e9db8 = 0x801e9db8;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_cc17d_string_edit_802796d4 0x802796d4 : { *(.text.w3d_cc17d_string_edit_802796d4) }
  .text.w3d_cc17d_set_target_name_8027a8a4 0x8027a8a4 : { *(.text.w3d_cc17d_set_target_name_8027a8a4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
