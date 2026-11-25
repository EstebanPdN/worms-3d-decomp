/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32a_chat_message_send_8003904c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
fn_800396a8 = 0x800396a8;
g_empty_804b06a0 = 0x804b06a0;
g_key_8041ab18 = 0x8041ab18;
g_key_8041ab28 = 0x8041ab28;
g_key_8041ab38 = 0x8041ab38;
g_key_8041ab48 = 0x8041ab48;
s8_index_query_800fc6dc = 0x800fc6dc;
s8_index_query_800fc7f8 = 0x800fc7f8;
s_80374064 = 0x80374064;
s_80374070 = 0x80374070;
s_80374080 = 0x80374080;
strcmp = 0x802ef234;
w3d_auto_80039b6c = 0x80039b6c;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_auto_800fc2b0 = 0x800fc2b0;
w3d_cx7a_message_construct_800a4ed0 = 0x800a4ed0;
w3d_d26k_send_serialized_8021e930 = 0x8021e930;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_d32a_chat_message_send_8003904c 0x8003904c : { *(.text.w3d_d32a_chat_message_send_8003904c) }
  .sdata 0x804abac0 (NOLOAD) : {
    . = 0x0; g_holder_804abac0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
