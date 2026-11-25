/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc38p_slot_table_destroy_full_801757a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__builtin_vec_delete = 0x801fe240;
cc38p_array_free_801fe240 = 0x801fe240;
cc38p_baseVtable_80412318 = 0x80412318;
cc38p_base_destroy_80210990 = 0x80210990;
cc38p_delete_801fe1f8 = 0x801fe1f8;
cc38p_release_all_801758e8 = 0x801758e8;
cc38p_storage_free_802134fc = 0x802134fc;
cc38p_tableVtable_80412250 = 0x80412250;
SECTIONS {
  .text.cc38p_slot_table_destroy_full_801757a4 0x801757a4 : { *(.text.cc38p_slot_table_destroy_full_801757a4) }
  .sdata 0x804ab5c4 (NOLOAD) : {
    . = 0x0; cc38p_globalTable_804ab5c4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
