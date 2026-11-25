/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_aim_update_80151a14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._11d24d_Handle = 0x80178474;
d24d_arena_alloc_801613f0 = 0x801613f0;
d24d_atan2_802e7e5c = 0x802e7e5c;
d24d_kind_message_80131b50 = 0x80131b50;
d24d_kind_query_800154e0 = 0x800154e0;
d24d_message_post_8016239c = 0x8016239c;
d24d_reset_8015286c = 0x8015286c;
d24d_sqrt_802e82c0 = 0x802e82c0;
d24d_worm_handle_800fc710 = 0x800fc710;
d24d_worm_info_800fc6dc = 0x800fc6dc;
d24d_zero_vector_8045e788 = 0x8045e788;
SECTIONS {
  .text.d24d_aim_update_80151a14 0x80151a14 : { *(.text.d24d_aim_update_80151a14) }
  .rodata 0x803a1988 : { *(.rodata) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; d24d_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
