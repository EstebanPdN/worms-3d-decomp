/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc39c_reset_active_worm_80098240)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc39c_active_worm_index_8037f744 = 0x8037f744;
cc39c_created_message_800c1620 = 0x800c1620;
cc39c_lookup_name_800fc1b0 = 0x800fc1b0;
cc39c_message_alloc_801613f0 = 0x801613f0;
cc39c_object_cast_803426b4 = 0x803426b4;
cc39c_post_current_8016239c = 0x8016239c;
cc39c_reference_index_80178c48 = 0x80178c48;
cc39c_scalar_8037f754 = 0x8037f754;
cc39c_set_scalar_8003e25c = 0x8003e25c;
cc39c_set_slot_word_8003e2e0 = 0x8003e2e0;
cc39c_set_vector_8003e23c = 0x8003e23c;
cc39c_set_word_8003e2bc = 0x8003e2bc;
cc39c_set_worm_8003e28c = 0x8003e28c;
cc39c_zero_8037f758 = 0x8037f758;
SECTIONS {
  .text.cc39c_reset_active_worm_80098240 0x80098240 : { *(.text.cc39c_reset_active_worm_80098240) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; cc39c_queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
