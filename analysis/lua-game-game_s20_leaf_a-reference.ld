/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_any_handle_set_8013f844)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803af62c = 0x803af62c;
lbl_803af630 = 0x803af630;
lbl_803af634 = 0x803af634;
lbl_803af638 = 0x803af638;
SECTIONS {
  .text.w3d_s20_any_handle_set_8013f844 0x8013f844 : { *(.text.w3d_s20_any_handle_set_8013f844) }
  .text.w3d_s20_sum_bytes_80177e04 0x80177e04 : { *(.text.w3d_s20_sum_bytes_80177e04) }
  .text.w3d_s20_sum_bytes_8017e1a0 0x8017e1a0 : { *(.text.w3d_s20_sum_bytes_8017e1a0) }
  .text.w3d_s20_evaluate_polynomial_80197244 0x80197244 : { *(.text.w3d_s20_evaluate_polynomial_80197244) }
  .text.w3d_s20_has_record_key_80199f68 0x80199f68 : { *(.text.w3d_s20_has_record_key_80199f68) }
  .text.w3d_s20_clear_word_slot_801a314c 0x801a314c : { *(.text.w3d_s20_clear_word_slot_801a314c) }
  .text.w3d_s20_set_byte_slot_801a9af4 0x801a9af4 : { *(.text.w3d_s20_set_byte_slot_801a9af4) }
  .text.w3d_s20_get_byte_slot_801a9b04 0x801a9b04 : { *(.text.w3d_s20_get_byte_slot_801a9b04) }
  .text.w3d_s20_select_band_801d69dc 0x801d69dc : { *(.text.w3d_s20_select_band_801d69dc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
