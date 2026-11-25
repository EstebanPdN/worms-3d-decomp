/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32a_chat_target_name_80039c1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
__6Stringi = 0x8020bcc0;
s_80373fe8 = 0x80373fe8;
s_80374060 = 0x80374060;
strcpy = 0x802ef2fc;
strlen = 0x802ef9c0;
strstr = 0x802efd14;
w3d_auto_80039b6c = 0x80039b6c;
w3d_heap_allocate_entry_b = 0x801fe220;
w3d_props_get_i32_80240bcc = 0x80240bcc;
w3d_props_get_object_80240994 = 0x80240994;
w3d_s21_get_item_8021eb48 = 0x8021eb48;
w3d_string_append = 0x8020bf2c;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_d32a_chat_target_name_80039c1c 0x80039c1c : { *(.text.w3d_d32a_chat_target_name_80039c1c) }
  .sdata 0x804abac0 (NOLOAD) : {
    . = 0x0; g_holder_804abac0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
