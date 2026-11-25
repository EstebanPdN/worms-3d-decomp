/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_set_low_bit_801865c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_set_low_bit_801865c0 0x801865c0 : { *(.text.w3d_s20_set_low_bit_801865c0) }
  .text.w3d_s20_set_matrix_80186614 0x80186614 : { *(.text.w3d_s20_set_matrix_80186614) }
  .text.w3d_s20_set_vectors_8018993c 0x8018993c : { *(.text.w3d_s20_set_vectors_8018993c) }
  .text.w3d_s20_count_active_entries_8018a800 0x8018a800 : { *(.text.w3d_s20_count_active_entries_8018a800) }
  .text.w3d_s20_find_record_8019a2a8 0x8019a2a8 : { *(.text.w3d_s20_find_record_8019a2a8) }
  .sdata 0x804b18ac (NOLOAD) : {
    . = 0x0; lbl_804b18ac = .;
    . = 0x4; lbl_804b18b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
