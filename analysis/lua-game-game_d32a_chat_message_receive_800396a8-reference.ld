/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32a_chat_message_receive_800396a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__6StringPCc = 0x8020bb54;
__6Stringi = 0x8020bcc0;
g_msg_table_8040db38 = 0x8040db38;
s8_index_query_800fc6dc = 0x800fc6dc;
s8_index_query_800fc7f8 = 0x800fc7f8;
s_80374060 = 0x80374060;
s_80374064 = 0x80374064;
strcmp = 0x802ef234;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_auto_800fc2b0 = 0x800fc2b0;
w3d_auto_80179598 = 0x80179598;
w3d_cached_message_id = 0x8015f5a0;
w3d_empty_80341584 = 0x80341584;
w3d_get_800a4f4c = 0x800a4f4c;
w3d_get_800a4f5c = 0x800a4f5c;
w3d_get_800a4f6c = 0x800a4f6c;
w3d_get_800a4f7c = 0x800a4f7c;
w3d_k5b_array_ref_lock_801ef048 = 0x801ef048;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_d32a_chat_message_receive_800396a8 0x800396a8 : { *(.text.w3d_d32a_chat_message_receive_800396a8) }
  .rodata 0x80374070 : { *(.rodata) }
  .sdata 0x804ad0b8 (NOLOAD) : {
    . = 0x0; g_id_804ad0b8 = .;
    . = 0x10; g_id_804ad0c8 = .;
    . = 0x469c; g_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
