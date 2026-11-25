/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d21a_owner_cycle_message_800258f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_component_handle_8015fb34 = 0x8015fb34;
w3d_listener_owner_80025b04 = 0x80025b04;
w3d_listener_setup_80025a1c = 0x80025a1c;
w3d_listener_stop_80025b34 = 0x80025b34;
w3d_message_id_equals_cache_8015f65c = 0x8015f65c;
w3d_message_post_8016239c = 0x8016239c;
w3d_set_handle_owner_80025aa0 = 0x80025aa0;
w3d_team_count_800fcea0 = 0x800fcea0;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d21a_owner_cycle_message_800258f4 0x800258f4 : { *(.text.w3d_d21a_owner_cycle_message_800258f4) }
  .sdata 0x804acad4 (NOLOAD) : {
    . = 0x0; w3d_message_804acad4 = .;
    . = 0x8; w3d_message_804acadc = .;
    . = 0x4c80; w3d_message_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
