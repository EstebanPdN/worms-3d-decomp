/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24a_chat_message_80038a70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_base_handler_8016293c = 0x8016293c;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_close_80038f50 = 0x80038f50;
w3d_message_id_equals_8015f65c = 0x8015f65c;
w3d_message_key_800a830c = 0x800a830c;
w3d_message_post_8016239c = 0x8016239c;
w3d_on_8003904c = 0x8003904c;
w3d_on_800396a8 = 0x800396a8;
w3d_open_80038e04 = 0x80038e04;
w3d_start_80038c74 = 0x80038c74;
w3d_stop_80038d18 = 0x80038d18;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d24a_chat_message_80038a70 0x80038a70 : { *(.text.w3d_d24a_chat_message_80038a70) }
  .sdata 0x804ad060 (NOLOAD) : {
    . = 0x0; w3d_message_804ad060 = .;
    . = 0x8; w3d_message_804ad068 = .;
    . = 0x10; w3d_message_804ad070 = .;
    . = 0x18; w3d_message_804ad078 = .;
    . = 0x20; w3d_message_804ad080 = .;
    . = 0x28; w3d_message_804ad088 = .;
    . = 0x30; w3d_message_804ad090 = .;
    . = 0x48; w3d_message_804ad0a8 = .;
    . = 0x46f4; w3d_message_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
