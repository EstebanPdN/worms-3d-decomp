/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_chat_close_80038f50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800a7e14 = 0x800a7e14;
FUN_801613f0 = 0x801613f0;
s8_property_write_800fc43c = 0x800fc43c;
w3d_app_leave_801298cc = 0x801298cc;
w3d_cached_message_id = 0x8015f5a0;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_string_80374034 = 0x80374034;
w3d_string_80374060 = 0x80374060;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.k5a_chat_close_80038f50 0x80038f50 : { *(.text.k5a_chat_close_80038f50) }
  .sdata 0x804ad0a0 (NOLOAD) : {
    . = 0x0; w3d_message_804ad0a0 = .;
    . = 0x10; w3d_message_804ad0b0 = .;
    . = 0x20; w3d_message_804ad0c0 = .;
    . = 0x46b4; w3d_message_pool_804b1754 = .;
    . = 0x46e8; w3d_context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
