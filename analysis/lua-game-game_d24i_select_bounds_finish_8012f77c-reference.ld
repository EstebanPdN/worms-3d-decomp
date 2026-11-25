/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_select_bounds_finish_8012f77c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24i_arena_alloc_801613f0 = 0x801613f0;
d24i_cached_id_8015f5a0 = 0x8015f5a0;
d24i_high_804668dc = 0x804668dc;
d24i_low_804668d0 = 0x804668d0;
d24i_notification_vtable_8040db38 = 0x8040db38;
d24i_post_8016239c = 0x8016239c;
d24i_select_slot_800a7e14 = 0x800a7e14;
d24i_text_8039d9b0 = 0x8039d9b0;
d24i_text_message_8010a8e0 = 0x8010a8e0;
d24i_update_value_80178d28 = 0x80178d28;
SECTIONS {
  .text.d24i_select_bounds_finish_8012f77c 0x8012f77c : { *(.text.d24i_select_bounds_finish_8012f77c) }
  .sdata 0x804af664 (NOLOAD) : {
    . = 0x0; d24i_message_804af664 = .;
    . = 0x8; d24i_message_804af66c = .;
    . = 0x40; d24i_message_804af6a4 = .;
    . = 0x20f0; d24i_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
