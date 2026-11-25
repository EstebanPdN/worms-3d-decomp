/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d43a_map_marks_collect_8001977c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_empty_8036a87c = 0x8036a87c;
malloc = 0x80212fd4;
memcpy_802eee50 = 0x802eee50;
strcmp = 0x802ef234;
w3d_actor_handle_member_destroy = 0x80126230;
w3d_actor_handle_member_initialize = 0x80126184;
w3d_actor_handle_member_set_slot_word = 0x801262e4;
w3d_actor_handle_member_set_word = 0x8012632c;
w3d_auto_8003f240 = 0x8003f240;
w3d_d30a_collect_named_80015960 = 0x80015960;
w3d_handle_clock_801264fc = 0x801264fc;
w3d_handle_member_call_80126334 = 0x80126334;
w3d_handle_member_query_8012629c = 0x8012629c;
w3d_handle_member_query_801262c0 = 0x801262c0;
w3d_handle_member_query_80126524 = 0x80126524;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_d43a_map_marks_collect_8001977c 0x8001977c : { *(.text.w3d_d43a_map_marks_collect_8001977c) }
  .rodata 0x8036a940 : { *(.rodata) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; w3d_game_804aa6d8 = .;
    . = 0x7c; w3d_marks_804aa754 = .;
    . = 0x84; g_named_804aa75c = .;
    . = 0x286; w3d_map_804aa95e = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
