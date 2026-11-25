/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_chat_open_80038e04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800a7e14 = 0x800a7e14;
FUN_801613f0 = 0x801613f0;
s8_property_write_800fc43c = 0x800fc43c;
w3d_app_enter_80129878 = 0x80129878;
w3d_cached_message_id = 0x8015f5a0;
w3d_h1_current_team_value_8021eb00 = 0x8021eb00;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_string_80374034 = 0x80374034;
w3d_string_80374040 = 0x80374040;
w3d_string_8037404c = 0x8037404c;
w3d_string_80374058 = 0x80374058;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.k5a_chat_open_80038e04 0x80038e04 : { *(.text.k5a_chat_open_80038e04) }
  .sdata 0x804abac0 (NOLOAD) : {
    . = 0x0; w3d_turn_context_804abac0 = .;
    . = 0x15d8; w3d_message_804ad098 = .;
    . = 0x15f8; w3d_message_804ad0b8 = .;
    . = 0x1600; w3d_message_804ad0c0 = .;
    . = 0x1610; w3d_message_804ad0d0 = .;
    . = 0x5c94; w3d_message_pool_804b1754 = .;
    . = 0x5cc8; w3d_context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
