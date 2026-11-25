/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19c_trigger_damage_801257f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d19c_arena_alloc_801613f0 = 0x801613f0;
d19c_cached_message_id_8015f5a0 = 0x8015f5a0;
d19c_message_payload_8040db38 = 0x8040db38;
d19c_message_post_8016239c = 0x8016239c;
d19c_property_write_800fc3b0 = 0x800fc3b0;
d19c_read_id_80178c48 = 0x80178c48;
d19c_team_record_800fc6dc = 0x800fc6dc;
d19c_trigger_destroy_8015fd1c = 0x8015fd1c;
d19c_trigger_hit_points_key_8039b964 = 0x8039b964;
d19c_trigger_index_key_8039b944 = 0x8039b944;
SECTIONS {
  .text.d19c_trigger_damage_801257f0 0x801257f0 : { *(.text.d19c_trigger_damage_801257f0) }
  .sdata 0x804af55c (NOLOAD) : {
    . = 0x0; d19c_trigger_damaged_message_804af55c = .;
    . = 0x8; d19c_trigger_destroyed_message_804af564 = .;
    . = 0x21f8; d19c_message_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
