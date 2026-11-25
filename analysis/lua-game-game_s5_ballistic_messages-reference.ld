/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_ballistic_schedule_800d8ed8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8003a264 = 0x8003a264;
w3d_ballistic_message_init_800e7c78 = 0x800e7c78;
w3d_message_allocate_801613f0 = 0x801613f0;
w3d_message_dispatch = 0x8015fc38;
w3d_message_post_current = 0x8016239c;
w3d_pool_release_800c56b8 = 0x800c56b8;
w3d_pool_schedule_800c53a0 = 0x800c53a0;
SECTIONS {
  .text.w3d_ballistic_schedule_800d8ed8 0x800d8ed8 : { *(.text.w3d_ballistic_schedule_800d8ed8) }
  .text.w3d_ballistic_post_owner_slot_800d8f8c 0x800d8f8c : { *(.text.w3d_ballistic_post_owner_slot_800d8f8c) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; w3d_message_pool_804b1754 = .;
    . = 0x4c; w3d_event_state_804b17a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
