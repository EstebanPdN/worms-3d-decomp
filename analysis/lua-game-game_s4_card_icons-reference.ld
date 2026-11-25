/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_card_initialize)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_aligned_allocate = 0x801fe2a8;
w3d_aligned_release = 0x801fe2e0;
w3d_cached_message_id = 0x8015f5a0;
w3d_card_begin_8028a570 = 0x8028a570;
w3d_card_callbacks_80466900 = 0x80466900;
w3d_card_copy_icon_80289088 = 0x80289088;
w3d_card_encode_80288bc8 = 0x80288bc8;
w3d_card_platform_init_80314794 = 0x80314794;
w3d_card_state_init_802ab990 = 0x802ab990;
w3d_flush_data_802fa988 = 0x802fa988;
w3d_resource_scope_enter_8015aee8 = 0x8015aee8;
w3d_resource_scope_leave_8015af24 = 0x8015af24;
w3d_str_803cf9c4 = 0x803cf9c4;
w3d_str_803cf9d0 = 0x803cf9d0;
w3d_str_803cf9dc = 0x803cf9dc;
w3d_str_803cf9e8 = 0x803cf9e8;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.w3d_s4_card_initialize 0x80288ab8 : { *(.text.w3d_s4_card_initialize) }
  .text.w3d_s4_card_release_buffer 0x80288b9c : { *(.text.w3d_s4_card_release_buffer) }
  .text.w3d_s4_card_copy_icons 0x80288fe8 : { *(.text.w3d_s4_card_copy_icons) }
  .sdata 0x804abb5c (NOLOAD) : {
    . = 0x0; w3d_slot_804abb5c = .;
    . = 0x50d0; w3d_cache_804b0c2c = .;
    . = 0x50d8; w3d_cache_804b0c34 = .;
    . = 0x50e0; w3d_cache_804b0c3c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
