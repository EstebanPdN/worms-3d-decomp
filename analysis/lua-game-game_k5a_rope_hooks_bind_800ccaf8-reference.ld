/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_rope_hooks_bind_800ccaf8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_801613f0 = 0x801613f0;
w3d_cached_message_id = 0x8015f5a0;
w3d_handle_set_name = 0x8015adf4;
w3d_message_post_current = 0x8016239c;
w3d_string_80387dd8 = 0x80387dd8;
w3d_string_80387de8 = 0x80387de8;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
w3d_subscribe_80162024 = 0x80162024;
w3d_target_id_message_801190b4 = 0x801190b4;
SECTIONS {
  .text.k5a_rope_hooks_bind_800ccaf8 0x800ccaf8 : { *(.text.k5a_rope_hooks_bind_800ccaf8) }
  .sdata 0x804ae84c (NOLOAD) : {
    . = 0x0; w3d_message_804ae84c = .;
    . = 0x8; w3d_message_804ae854 = .;
    . = 0x10; w3d_message_804ae85c = .;
    . = 0x2f08; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
