/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_hit_list_remove_801534e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_actor_id_800a830c = 0x800a830c;
d24d_arena_alloc_801613f0 = 0x801613f0;
d24d_message_id_8015f5a0 = 0x8015f5a0;
d24d_message_init_800a82f0 = 0x800a82f0;
d24d_message_post_8016239c = 0x8016239c;
d24d_owner_matches_8014c488 = 0x8014c488;
SECTIONS {
  .text.d24d_hit_list_remove_801534e0 0x801534e0 : { *(.text.d24d_hit_list_remove_801534e0) }
  .sdata 0x804afc70 (NOLOAD) : {
    . = 0x0; d24d_removed_key_804afc70 = .;
    . = 0x1ae4; d24d_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
