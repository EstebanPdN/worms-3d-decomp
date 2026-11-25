/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_worm_start_announce_80073050)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_801613f0 = 0x801613f0;
s8_index_query_800fc6dc = 0x800fc6dc;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_cached_message_id = 0x8015f5a0;
w3d_int_message_init_80125fdc = 0x80125fdc;
w3d_message_int_init = 0x800a82f0;
w3d_message_post_current = 0x8016239c;
w3d_string_8037cdc8 = 0x8037cdc8;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.k5a_worm_start_announce_80073050 0x80073050 : { *(.text.k5a_worm_start_announce_80073050) }
  .sdata 0x804ad964 (NOLOAD) : {
    . = 0x0; w3d_message_804ad964 = .;
    . = 0x10; w3d_message_804ad974 = .;
    . = 0x18; w3d_message_804ad97c = .;
    . = 0x20; w3d_message_804ad984 = .;
    . = 0x28; w3d_message_804ad98c = .;
    . = 0x3df0; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
