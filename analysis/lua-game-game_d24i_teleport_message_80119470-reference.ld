/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_teleport_message_80119470)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24i_arena_alloc_801613f0 = 0x801613f0;
d24i_base_handle_8015fb34 = 0x8015fb34;
d24i_cached_id_8015f5a0 = 0x8015f5a0;
d24i_can_jump_80119aa8 = 0x80119aa8;
d24i_finish_8015fd1c = 0x8015fd1c;
d24i_id_equals_8015f65c = 0x8015f65c;
d24i_jump_80119794 = 0x80119794;
d24i_notification_vtable_8040db38 = 0x8040db38;
d24i_post_8016239c = 0x8016239c;
d24i_setup_80119590 = 0x80119590;
d24i_shutdown_801196d8 = 0x801196d8;
SECTIONS {
  .text.d24i_teleport_message_80119470 0x80119470 : { *(.text.d24i_teleport_message_80119470) }
  .sdata 0x804af31c (NOLOAD) : {
    . = 0x0; d24i_stop_804af31c = .;
    . = 0x10; d24i_fire_804af32c = .;
    . = 0x40; d24i_notify_804af35c = .;
    . = 0x2438; d24i_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
