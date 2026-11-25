/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k11b_swap_value_802f778c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_k11b_swap_value_802f778c 0x802f778c : { *(.text.w3d_k11b_swap_value_802f778c) }
  .text.w3d_k11b_clear_pair_802f9f64 0x802f9f64 : { *(.text.w3d_k11b_clear_pair_802f9f64) }
  .text.w3d_k11b_clear_pair_802ffcf8 0x802ffcf8 : { *(.text.w3d_k11b_clear_pair_802ffcf8) }
  .text.w3d_k11b_raise_flag_80300c18 0x80300c18 : { *(.text.w3d_k11b_raise_flag_80300c18) }
  .text.w3d_k11b_get_word_80304c00 0x80304c00 : { *(.text.w3d_k11b_get_word_80304c00) }
  .text.w3d_k11b_get_word_80306cb8 0x80306cb8 : { *(.text.w3d_k11b_get_word_80306cb8) }
  .text.w3d_k11b_copy_first_word_803096a4 0x803096a4 : { *(.text.w3d_k11b_copy_first_word_803096a4) }
  .text.w3d_k11b_get_field_14_8030a080 0x8030a080 : { *(.text.w3d_k11b_get_field_14_8030a080) }
  .text.w3d_k11b_get_half_80314840 0x80314840 : { *(.text.w3d_k11b_get_half_80314840) }
  .text.w3d_k11b_get_field_88_80314bd4 0x80314bd4 : { *(.text.w3d_k11b_get_field_88_80314bd4) }
  .text.w3d_k11b_get_field_84_80314fd8 0x80314fd8 : { *(.text.w3d_k11b_get_field_84_80314fd8) }
  .sdata 0x804ac5e4 (NOLOAD) : {
    . = 0x0; lbl_804ac5e4 = .;
    . = 0x4c74; lbl_804b1258 = .;
    . = 0x4cb0; lbl_804b1294 = .;
    . = 0x4d34; lbl_804b1318 = .;
    . = 0x4e64; lbl_804b1448 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
