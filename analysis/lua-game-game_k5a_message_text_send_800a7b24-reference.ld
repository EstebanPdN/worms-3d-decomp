/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_message_text_send_800a7b24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800f985c = 0x800f985c;
FUN_801613f0 = 0x801613f0;
w3d_engine_get_context = 0x80165254;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.k5a_message_text_send_800a7b24 0x800a7b24 : { *(.text.k5a_message_text_send_800a7b24) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
