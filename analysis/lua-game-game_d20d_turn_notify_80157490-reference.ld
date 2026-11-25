/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d20d_turn_notify_80157490)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s8_index_query_800fc6dc = 0x800fc6dc;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_80178c48 = 0x80178c48;
w3d_cached_message_id = 0x8015f5a0;
w3d_empty_803426b4 = 0x803426b4;
w3d_message_int_init = 0x800a82f0;
w3d_message_post_current = 0x8016239c;
w3d_message_table_8040db38 = 0x8040db38;
SECTIONS {
  .text.d20d_turn_notify_80157490 0x80157490 : { *(.text.d20d_turn_notify_80157490) }
  .sdata 0x804afe88 (NOLOAD) : {
    . = 0x0; w3d_message_key_804afe88 = .;
    . = 0x68; w3d_message_key_804afef0 = .;
    . = 0x80; w3d_message_key_804aff08 = .;
    . = 0x98; w3d_message_key_804aff20 = .;
    . = 0xd0; w3d_message_key_804aff58 = .;
    . = 0xd8; w3d_message_key_804aff60 = .;
    . = 0x18cc; w3d_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
