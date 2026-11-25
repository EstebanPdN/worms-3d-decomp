/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_worm_index_announce_80068240)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_801613f0 = 0x801613f0;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_cached_message_id = 0x8015f5a0;
w3d_int_message_init_80125fdc = 0x80125fdc;
w3d_message_int_init = 0x800a82f0;
w3d_message_post_current = 0x8016239c;
w3d_string_8037a214 = 0x8037a214;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.k5a_worm_index_announce_80068240 0x80068240 : { *(.text.k5a_worm_index_announce_80068240) }
  .sdata 0x804ad5f8 (NOLOAD) : {
    . = 0x0; w3d_message_804ad5f8 = .;
    . = 0x10; w3d_message_804ad608 = .;
    . = 0x18; w3d_message_804ad610 = .;
    . = 0x415c; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
